/* Nome: Pedro Chinen */
/* RA: 175828 */
/* Laboratorio 05 - Pareamento de Grifos */

/* para este laboratório, poderão ser utilizadas apenas variáveis
   simples, operações de entrada e saída, operações aritméticas,
   desvios condicionais, estruturas de repetição e vetores
   unidimensionais */

#include <stdio.h>
#include <stdlib.h>

const int RAIZ2 = 1;
const int SEMINFO = 0;
const int NATURAL = 1;
const int REVERSA = 2;
const int INCOMPATIVEL = 3;

int main(){

  /* Quantidade de passos da fêmea e do macho */
  int passosF, passosM;

  /* Danca -> conjunto de passos -> direção e distância */
  int *dancaF, *dancaM;
  
  /* Posições de inicio de cada fase */
  int fase2F, fase3F;
  int fase2M, fase3M;
  /* int faseAtual; */

  /* Que tipo de compatibilidade */
  int compatibilidade;

  /* Contadores e auxiliares*/
  int i, ultimaDirecao, ultimaDistancia,
    proximaProporcaoDirecao, proporcaoDirecao,
    direcao, distancia,
    x, y, w, v;
  float  proximaProporcaoDistancia, proporcaoDistancia;
  
  /* Ler entrada 
     Quantidade de passos da fêmea, Quantidade de passos do macho
     Lista de passos da fêmea (direção e distância)
     Lista de passos do macho (direção e distância) 

     Todas as fases da dança da fêmea têm no mínimo 2 passos
  */

  scanf("%d %d", &passosF, &passosM);

  dancaF = malloc(passosF * 2 * sizeof(int));
  dancaM = malloc(passosM * 2 * sizeof(int));

  x = 0;
  y = 0;
  w = 0;
  v = 0;

  fase2F = -1;
  fase3F = -1;

  for(i = 0; i < passosF*2; i=i+2){
    scanf("%d %d", &direcao, &distancia);

    /* Insere no vetor da danca da fêmea */
    dancaF[i] = direcao;
    dancaF[i+1] = distancia;
    
    /* Achar inicio da fase 2  */
    if(fase2F == -1){

      switch(direcao){
      case 0: 
	y += distancia;
	break;
      case 1: 
	w += distancia;
	break;
      case 2: 
	x += distancia;
	break;
      case 3: 
	v += distancia;
	break;
      case 4: 
	y -= distancia;
	break;
      case 5: 
	w -= distancia;
	break;
      case 6: 
	x -= distancia;
	break;
      case 7: 
	v -= distancia;
	break;
      }

      /* Se voltou para a posicao inicial mostrar que eh o inicio da
	 fase 2, e inicializa para achar o inicio da fase 3 */
      if(x == 0 && y == 0 && v == 0 && w == 0){
	fase2F = i+2;
	ultimaDirecao = direcao;
	ultimaDistancia = distancia;
      }
    }

    /* Achar inicio da fase 3  */
    else if(fase3F == -1){
      if(direcao - 4 == ultimaDirecao || 
	 direcao == ultimaDirecao || 
	 direcao + 4 == ultimaDirecao){
	if(distancia > ultimaDistancia){
	  fase3F = i+2;
	}
      }

      ultimaDirecao = direcao;
      ultimaDistancia = distancia;
    }
  }


  /* printf("Danca Femea: \n"); */
  /* for(i = 0; i < passosF*2; i=i+2){ */
  /*   printf("%d %d ", dancaF[i], dancaF[i+1]); */
  /* } */
  /* printf("\n"); */
  /* for(i = 0; i < fase2F; i=i+2){ */
  /*   printf("%d %d ", dancaF[i], dancaF[i+1]); */
  /* } */
  /* printf("\n"); */
  /* for(i = fase2F; i < fase3F; i=i+2){ */
  /*   printf("%d %d ", dancaF[i], dancaF[i+1]); */
  /* } */
  /* printf("\n"); */
  /* for(i = fase3F; i < passosF*2; i=i+2){ */
  /*   printf("%d %d ", dancaF[i], dancaF[i+1]); */
  /* } */
  /* printf("\n2F: %d 3F: %d\n", fase2F, fase3F); */
  /* printf("-------------------------------------\n"); */


  /* Fêmea tem 3 fases 
     
     1- Começa no inicio dos passos. Termina quando ela volta para 
     o ponto de partida da dança. 
     
     2- Começa logo após a primeira. Termina quando a fêmea faz um
     passo em alguma direção (não necessariamente sentido) e
     imediatamente faz um passo maior para a mesma direção.

     Guarda ultima direção e ultima distância. Se distância atual for 
     maior e direção for a mesma, acabou a segunda fase

     3- Começa logo após a segunda. Termina quando a fêmea para
     completamente.
   */

  compatibilidade = SEMINFO;
  fase2M = -1;
  fase3M = -1;

  /* Processa o primeiro registro fora do loop */
  scanf("%d %d", &direcao, &distancia);
  dancaM[0] = direcao;
  dancaM[1] = distancia;

  ultimaDirecao = direcao;
  ultimaDistancia = distancia;

  proximaProporcaoDistancia = dancaF[1] / dancaF[3];
  if(proximaProporcaoDistancia < 0){
    proximaProporcaoDistancia = dancaF[3] / dancaF[1];
  }

  proximaProporcaoDirecao = (dancaF[2] + dancaF[0]) % 8;
  x = (dancaF[2] - dancaF[0]) % 8;
  if(x < 0){
    x = x * -1;
  }
  if(x < proximaProporcaoDirecao){
    proximaProporcaoDirecao = x;
  }
  
  /* Começa do segundo registro  */
  for(i = 2; i < passosM*2; i=i+2){
    scanf("%d %d", &direcao, &distancia);
    dancaM[i] = direcao;
    dancaM[i+1] = distancia;

    /* Se nao sei compatibilidade, ver se ainda eh compativel */
    if(compatibilidade == SEMINFO){

      /* Achar inicio da fase 2  */
      if(fase2M == -1){

	proporcaoDirecao = (direcao + ultimaDirecao) % 8;
	if(proporcaoDirecao > 8){
	  proporcaoDirecao++;
	}
	x = (direcao - ultimaDirecao) % 8;
	if(direcao + ultimaDirecao > 8){
	  proporcaoDirecao += 2;
	}
	if(x < 0){
	  x += 8;
	}
	if(x < proporcaoDirecao){
	  proporcaoDirecao = x;
	}

	proporcaoDistancia = distancia / ultimaDistancia;
	x = ultimaDistancia / distancia;
	if(x > proporcaoDistancia){
	  proporcaoDistancia = x;
	}
	
	/* Angulos nao preservados: Incompativel */
	if(proporcaoDirecao != proximaProporcaoDirecao){
	  compatibilidade = INCOMPATIVEL;
	  /* printf("bbbbbbbbbbbbbb\n"); */
	}else{
	  /* Passo da Fêmea eh maior que do macho ou
	     Proporcao Distancia nao for consistente: Incompativel  */
	  if(distancia < dancaF[i+1]|| 
	     proporcaoDistancia != proximaProporcaoDistancia){

	    /* printf("aaaaaaaaaaaaaaaaaaaaaaa\n"); */
	    compatibilidade = INCOMPATIVEL;
	  }else{

	    /* Atualizar proporcoes distancia e direcao */
	    proximaProporcaoDirecao = (dancaF[i] + dancaF[i+2]) % 8;
	    x = (dancaF[i+2] - dancaF[i]) % 8;
	    if(dancaF[i] + dancaF[i+2] >= 8){
	      proximaProporcaoDirecao += 2;
	    }
	    if(x < 0){
	      x += 8;
	    }
	    if(x < proximaProporcaoDirecao){
	      proximaProporcaoDirecao = x;
	    }

	    proximaProporcaoDistancia = dancaF[i+1] / dancaF[i+3];	    
	    x = dancaF[i+3] / dancaF[i+1];
	    if(x > proximaProporcaoDistancia){
	      proximaProporcaoDistancia = x;
	    }

	    /* Se a quantidade de passos for igual: Achou inicio fase2F*/
	    if(i == fase2F-2){
	      fase2M = i+2;
	    }
	  }
	}

	/* Se primeira fase tem mais passos que a fêmea: Incompativel  */
	if(i > fase2F){
	  /* printf("-----------------------\n"); */
	  compatibilidade = INCOMPATIVEL;
	}


	ultimaDirecao = direcao;
	ultimaDistancia = distancia;
      }

      /* Achar inicio da fase 3  */
      else if(fase3M == -1){

	if(direcao - 4 == ultimaDirecao || 
	   direcao == ultimaDirecao || 
	   direcao + 4 == ultimaDirecao){
	  if(distancia > ultimaDistancia){
	    fase3M = i+2;
	    if(fase3F - fase3M < 0){
	      /* printf("====================%d %d \n", fase3M, fase3F); */
	      compatibilidade = INCOMPATIVEL;
	    }

	    proximaProporcaoDistancia = dancaF[i+3] / dancaF[i+5];
	    if(proximaProporcaoDistancia < 0){
	      proximaProporcaoDistancia = dancaF[i+5] / dancaF[i+3];
	    }

	    proximaProporcaoDirecao = (dancaF[i+4] + dancaF[i+2]) % 8;
	    x = (dancaF[i+4] - dancaF[i+2]) % 8;
	    if(x < 0){
	      x = x * -1;
	    }
	    if(x < proximaProporcaoDirecao){
	      proximaProporcaoDirecao = x;
	    }
	  }
	}

	ultimaDirecao = direcao;
	ultimaDistancia = distancia;
      }

      /* Ver fase 3 */
      else{
	proporcaoDirecao = (direcao + ultimaDirecao) % 8;
	if(proporcaoDirecao > 8){
	  proporcaoDirecao++;
	}
	x = (direcao - ultimaDirecao) % 8;
	if(direcao + ultimaDirecao > 8){
	  proporcaoDirecao += 2;
	}
	if(x < 0){
	  x += 8;
	}
	if(x < proporcaoDirecao){
	  proporcaoDirecao = x;
	}

	proporcaoDistancia = distancia / ultimaDistancia;
	x = ultimaDistancia / distancia;
	if(x > proporcaoDistancia){
	  proporcaoDistancia = x;
	}
	
	/* Angulos nao preservados: Incompativel */
	y = (direcao + dancaF[i]) % 8;
	if(direcao + dancaF[i] > 8){
	  y++;
	}
	
	if(direcao > dancaF[i]){
	  x = (direcao - dancaF[i]) % 8;	    
	}else{
	  x = (dancaF[i] - direcao) % 8;
	}

	if(x == 7){
	  x = 1;
	}

	/* printf("== %d %d\n", y, x); */
	if(x < y){
	  y = x;
	}

	/* printf("%d| (%d %d | %d %d) [%d %d | %d %d]\n", i,  */
	/*        direcao, ultimaDirecao, */
	/*        dancaF[i], dancaF[i-2], */
	/*        distancia, ultimaDistancia, */
	/*        dancaF[i+1], dancaF[i-1]); */

	/* printf("%d| (%d %d) [%f %f]\n", i,  */
	/*        proporcaoDirecao, proximaProporcaoDirecao, */
	/*        proporcaoDistancia, proximaProporcaoDistancia); */
	


	if(y > 1){
	  compatibilidade = INCOMPATIVEL;
	  /* printf("bbbbbbbbbbbbbb\n"); */
	}else{
	  /* Passo da Fêmea eh maior que do macho ou
	     Proporcao Distancia nao for consistente: Incompativel  */
	  if(direcao + dancaF[i] || 
	     proporcaoDistancia != proximaProporcaoDistancia){

	    /* printf("aaaaaaaaaaaaaaaaaaaaaaa\n"); */
	    compatibilidade = INCOMPATIVEL;
	  }else{

	    /* Atualizar proporcoes distancia e direcao */
	    proximaProporcaoDirecao = (dancaF[i] + dancaF[i+2]) % 8;
	    x = (dancaF[i+2] - dancaF[i]) % 8;
	    if(dancaF[i] + dancaF[i+2] >= 8){
	      proximaProporcaoDirecao += 2;
	    }
	    if(x < 0){
	      x += 8;
	    }
	    if(x < proximaProporcaoDirecao){
	      proximaProporcaoDirecao = x;
	    }

	    proximaProporcaoDistancia = dancaF[i+1] / dancaF[i+3];	    
	    x = dancaF[i+3] / dancaF[i+1];
	    if(x > proximaProporcaoDistancia){
	      proximaProporcaoDistancia = x;
	    }

	    if(i == passosM * 2 - 2){
	      compatibilidade = NATURAL;
	    }

	  }
	}
	
	if((passosM*2 - fase3M) - (passosF - fase3F) < 0){
	  /* printf("cccccccccccc\n"); */
	  compatibilidade = INCOMPATIVEL;
	}
      }
    }
  }

  if(compatibilidade == SEMINFO){
    compatibilidade = NATURAL;
  }

  /* printf("Comp: %d\n", compatibilidade); */

  /* printf("Danca Macho: \n"); */
  /* for(i = 0; i < passosM*2; i=i+2){ */
  /*   printf("%d %d ", dancaM[i], dancaM[i+1]); */
  /* } */
  /* printf("\n"); */
  /* for(i = 0; i < fase2M; i=i+2){ */
  /*   printf("%d %d ", dancaM[i], dancaM[i+1]); */
  /* } */
  /* printf("\n"); */
  /* for(i = fase2M; i < fase3M; i=i+2){ */
  /*   printf("%d %d ", dancaM[i], dancaM[i+1]); */
  /* } */
  /* printf("\n"); */
  /* for(i = fase3M; i < passosM*2; i=i+2){ */
  /*   printf("%d %d ", dancaM[i], dancaM[i+1]); */
  /* } */
  /* printf("\n2M: %d 3M: %d\n", fase2M, fase3M); */

  /* Verificar a compatibilidade do macho 

     Ir colocando no vetor de passos do macho. Se ainda não deu
     imcompatibilidade fazer os testes

     1- A dança do macho deve ter a mesma forma que da fêmea. mantendo
     a proporcionalidade entre as amplitudes dos passos. Mantendo os
     angulos.

     Pegar passo do macho e comparar com o da fêmea. Proporcao das
     distancia fêmea / macho. Direção dos passos fêmea - macho, sempre
     tem que ser igual.
     
     Se um não for, ja pode dar imcompatibilidade

     2- Não pode ultrapassar a quantidade de passos da fêmea. Marca o
     final dos passos da mesma maneira que a fêmea.

     Ir vendo o incio do terceira fase.

     Quando souber quando começa a terceira fase, podemos verificar a
     quantiadde de passos do macho. Quantidade de passos da femea =
     (inicio terceira fase - inicior 2 fase ) / 2. Pois cada passo tem
     direção e distancia.

     Se não for, ja pode dar imcompatibilidade

     3- Relevante a proporção entre as amplitudes dos passos. Angulos
     podem errar até 60º para mais ou para menos. Número de passos tem
     que ser o mesmo que o da fêmea.

     Proporcao das distancia fêmea - macho. Direção dos passos
     fêmea-macho, devem estar no intervalo de direção +-1.

     Se um não for, ja pode dar imcompatibilidade
   */

  /* A dança do macho pode ser revertida no tempo para verificar se o
     macho é reversamente compatível com a fêmea 
     
     Se for compatibilidade natural, não fazer nada.

     Percorrer o vetor de tras para frente, fazendo as mesmas validações.
     Se uma delas não der certo, não precisa continuar tentando. */

  /* Escrever Saida 
     Compatibilidade do casal
   */

  

  return 0;
}
