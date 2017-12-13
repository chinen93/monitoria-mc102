/*
  Pedro Hideki Uiechi Chinen
  RA: 175828

  Laboratório 6 - It's me, Mario!
*/


/* 
   Estimulador de tempo: total de ilhas, ou regiões, em um mapa e o
   tempo médio de jogo de cada uma das ilhas

   Tarefa: Total de Ilhas em um mapa.

   Regiões = cor preta == 1
   Água = cor branca == 0


   Entrada:
   P1 : identificador de imagem PBM
   W H: W largura da matriz de pixels, H altura da matriz de pixels
   Matriz (HxW) com valores 1 ou 0
  
   Saída:
   Quantidade de Ilhas no mapa


   Observações:
   Mapa máximo 300px por 300px, Não são necessáriamente quadrados
   Ilha não contém buracos em seu interior
   Qualquer doir 8 pixels vizinhos conectam os pedaços de uma ilha

   Uso apenas de variáveis simples, vetores, matrizes, operaçõs de
   entrada e saída, operações aritméticas, desvis condicionais e
   laços.

   Algoritmo:
   Carrega Matriz.
   Inicializa Contador de ilhas
   Percorre todos as linhas
     Percorre todas as colunas
       Verifica se o elemento atual é diferente de àgua
              
 */


#include <stdio.h>
#include <stdlib.h>

void imprime(int matriz[300][300], int height, int width){
  int i, j;
  for(j=0; j<width; j++){
    printf("%d ", j%10);
  }
  printf("\n");
  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }
}

int main(){

  char a,b;
  int width, height;
  int i, j, aux, k, l;
  int matriz[300][300];
  int contador = 0;
  int ILHA = 1, A_VISITAR = 2, VISITADO = 3;
  int ilhaJaPassada, oldIlhaJaPassada, vizinhoVISITADO;


  scanf("%c%c %d %d",&a,&b,&width,&height);

  /* Carregar a Matriz  */
  for(i=0; i<height; i++)
    for(j=0; j<width; j++){
      scanf("%d", &aux);
      matriz[i][j] = aux;
    }


  imprime(matriz, height, width);
  printf("----------------------------\n");

  /* Percorrer todos os elementos da matriz */
  for(i=0; i<height; i++){
    /* oldIlhaJaPassada = ilhaJaPassada; */
    /* ilhaJaPassada = 0; */

    for(j=0; j<width; j++){
      /* Pegar informação do elemento e marca ele como visitado*/
      aux = matriz[i][j];

      /* Se elemento for uma ilha não visitada */
      if(aux == ILHA || aux == A_VISITAR){
	oldIlhaJaPassada = ilhaJaPassada;
	ilhaJaPassada = 0;
	vizinhoVISITADO = 0;
	
       
	/* /\* Noroeste *\/ */
	if(i-1 >= 0 && j-1 >= 0){

	  /* Se for uma ilha a visitar, decrementar contador de ilhas*/
	  if(matriz[i-1][j-1] == A_VISITAR || matriz[i-1][j-1] == VISITADO){
	    oldIlhaJaPassada = ilhaJaPassada;
	    ilhaJaPassada = 1;
	    k = i-1;
	    l = j-1;
	    if(matriz[k][l] == VISITADO){
	      vizinhoVISITADO = 1;
	    }
	  }
	}

	/* /\* Norte *\/ */
	/* if(i-1 >= 0){ */

	/*   /\* Se for uma ilha a visitar, decrementar contador de ilhas*\/ */
	/*   if(matriz[i-1][j] == A_VISITAR || matriz[i-1][j] == VISITADO){ */
	/*     ilhaJaPassada = 1; */
	/*   } */
	/* } */

	/* Nordeste */
	if(i-1 >= 0 && j+1 < width){

	  /* Se for uma ilha a visitar, decrementar contador de ilhas*/
	  if(matriz[i-1][j+1] == A_VISITAR || matriz[i-1][j+1] == VISITADO){
	    oldIlhaJaPassada = ilhaJaPassada;
	    ilhaJaPassada = 1;
	    k = i-1;
	    l = j+1;
	    if(matriz[k][l] == VISITADO){
	      vizinhoVISITADO = 1;
	    }
	  }
	}

	/* /\* Oeste *\/ */
	if(j+1 < width){

	  /* Se for uma ilha a visitar, decrementar contador de ilhas*/
	  if(matriz[i][j-1] == A_VISITAR || matriz[i][j-1] == VISITADO){
	    oldIlhaJaPassada = ilhaJaPassada;
	    ilhaJaPassada = 1;
	    k = i;
	    l = j-1;
	    if(matriz[k][l] == VISITADO){
	      vizinhoVISITADO = 1;
	    }
	  }
	}

	/* Vizinho Leste */
	if(j+1 < width){
	  /* Se for uma ilha a visitar, decrementar contador de ilhas*/
	  if(matriz[i][j+1] == A_VISITAR || matriz[i][j+1] == VISITADO){
	    oldIlhaJaPassada = ilhaJaPassada;
	    ilhaJaPassada = 1;
	    k = i;
	    l = j+1;
	    if(matriz[k][l] == VISITADO){
	      vizinhoVISITADO = 1;
	    }
	    matriz[k][l] = VISITADO;
	    if(l+1 < width){
	      if(matriz[k][l+1] == A_VISITAR){
	    	matriz[k][l+1] = VISITADO;
	      }
	      if(matriz[k][l+1] == ILHA){
	    	matriz[k][l+1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l-1 >= 0){
	      if(matriz[k+1][l-1] == A_VISITAR){
	    	matriz[k+1][l-1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height){
	      if(matriz[k+1][l] == A_VISITAR){
	    	matriz[k+1][l] = VISITADO;
	      }
	      if(matriz[k+1][l] == ILHA){
	    	matriz[k+1][l] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l+1 < width){
	      if(matriz[k+1][l+1] == A_VISITAR){
	    	matriz[k+1][l+1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	  }
	  /* Se for uma ilha, marcar como visitado */
	  if(matriz[i][j+1] == ILHA){
	    matriz[i][j+1] = A_VISITAR;
	  }
	}

	/* Vizinho Sudoeste */
	if(i+1 < height && j-1 >= 0){

	  /* Se for uma ilha a visitar, decrementar contador de ilhas*/
	  if(matriz[i+1][j-1] == A_VISITAR || matriz[i+1][j-1] == VISITADO){
	    oldIlhaJaPassada = ilhaJaPassada;
	    ilhaJaPassada = 1;
	    k = i+1;
	    l = j-1;
	    if(matriz[k][l] == VISITADO){
	      vizinhoVISITADO = 1;
	    }
	    matriz[k][l] = VISITADO;

	    if(l+1 < width){
	      if(matriz[k][l+1] == A_VISITAR){
	    	matriz[k][l+1] = VISITADO;
	      }
	      if(matriz[k][l+1] == ILHA){
	    	matriz[k][l+1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l-1 >= 0){
	      if(matriz[k+1][l-1] == A_VISITAR){
	    	matriz[k+1][l-1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height){
	      if(matriz[k+1][l] == A_VISITAR){
	    	matriz[k+1][l] = VISITADO;
	      }
	      if(matriz[k+1][l] == ILHA){
	    	matriz[k+1][l] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l+1 < width){
	      if(matriz[k+1][l+1] == A_VISITAR){
	    	matriz[k+1][l+1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	  }

	  /* Se for uma ilha, marcar como visitado */
	  if(matriz[i+1][j-1] == ILHA){
	    matriz[i+1][j-1] = A_VISITAR;
	  }
	}

	/* Vizinho Sul */
	if(i+1 < height){

	  /* Se for uma ilha a visitar, decrementar contador de ilhas*/
	  if(matriz[i+1][j] == A_VISITAR || matriz[i+1][j] == VISITADO){
	    oldIlhaJaPassada = ilhaJaPassada;
	    ilhaJaPassada = 1;
	    k = i+1;
	    l = j;
	    if(matriz[k][l] == VISITADO){
	      vizinhoVISITADO = 1;
	    }
	    matriz[k][l] = VISITADO;
	    if(l+1 < width){
	      if(matriz[k][l+1] == A_VISITAR){
	    	matriz[k][l+1] = VISITADO;
	      }
	      if(matriz[k][l+1] == ILHA){
	    	matriz[k][l+1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l-1 >= 0){
	      if(matriz[k+1][l-1] == A_VISITAR){
	    	matriz[k+1][l-1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height){
	      if(matriz[k+1][l] == A_VISITAR){
	    	matriz[k+1][l] = VISITADO;
	      }
	      if(matriz[k+1][l] == ILHA){
	    	matriz[k+1][l] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l+1 < width){
	      if(matriz[k+1][l+1] == A_VISITAR){
	    	matriz[k+1][l+1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	  }
	  /* Se for uma ilha, marcar como visitado */
	  if(matriz[i+1][j] == ILHA){
	    matriz[i+1][j] = A_VISITAR;
	  }
	}

	/* Vizinho Sudeste */
	if(i+1 < height && j+1 < width){

	  /* Se for uma ilha a visitar, decrementar contador de ilhas*/
	  if(matriz[i+1][j+1] == A_VISITAR || matriz[i+1][j+1] == VISITADO){
	    oldIlhaJaPassada = ilhaJaPassada;
	    ilhaJaPassada = 1;
	    k = i+1;
	    l = j+1;
	    if(matriz[k][l] == VISITADO){
	      vizinhoVISITADO = 1;
	    }
	    matriz[k][l] = VISITADO;
	    if(l+1 < width){
	      if(matriz[k][l+1] == A_VISITAR){
	    	matriz[k][l+1] = VISITADO;
	      }
	      if(matriz[k][l+1] == ILHA){
	    	matriz[k][l+1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l-1 >= 0){
	      if(matriz[k+1][l-1] == A_VISITAR){
	    	matriz[k+1][l-1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	    if(k+1 < height){
	      if(matriz[k+1][l] == A_VISITAR){
	    	matriz[k+1][l] = VISITADO;
	      }
	      if(matriz[k+1][l] == ILHA){
	    	matriz[k+1][l] = A_VISITAR;
	      }
	    }
	    if(k+1 < height && l+1 < width){
	      if(matriz[k+1][l+1] == A_VISITAR){
	    	matriz[k+1][l+1] = VISITADO;
	      }
	      if(matriz[k+1][l-1] == ILHA){
	    	matriz[k+1][l-1] = A_VISITAR;
	      }
	    }
	  }
	  /* Se for uma ilha, marcar como visitado */
	  if(matriz[i+1][j+1] == ILHA){
	    matriz[i+1][j+1] = A_VISITAR;
	  }
	}

	/* Achou uma ilha nova, aumenta contador */
	/* if(aux == ILHA && ilhaJaPassada == 0){ */
	/*   contador++; */
	/* } */

	/* if(oldIlhaJaPassada == 1 && ilhaJaPassada == 0){ */
	/*   contador--; */
	/* } */

	if(aux == ILHA && ilhaJaPassada == 0){
	  contador++;
	}
	
	printf("------ %d\n", vizinhoVISITADO);
	if(ilhaJaPassada == 1 && vizinhoVISITADO == 0 && aux != ILHA){
	  printf("BLA\n");
	  contador--;
	}


	if(contador < -1){
	  printf("-------------------------------------------------\n");
	  return 1;
	}

	if(i > 11){
	  printf("-------------------------------aaaaaaaaaaaaaaaaaaaaaaa\n");
	  return 1;
	}


	matriz[i][j] = VISITADO;

	printf("[%d %d] %d\n", i,j, aux);	
	imprime(matriz, height, width);
	printf("%d %d %d\n", contador, ilhaJaPassada, oldIlhaJaPassada);
	printf("================================\n");
      }
    }
  }

  /* printf("%d %d\n", width, height); */
  printf("%d\n", contador);

  return 0; 
}


