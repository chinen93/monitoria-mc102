/* Nome: Pedro Chinen */
/* RA: 175828 */
/* Laboratorio 04 - Space Invaders */

#include <stdio.h>

int main(){

  int dimensao;
  int linha1, coluna1, linha2, coluna2, linha3, coluna3, linha4, coluna4, linha5, coluna5;
  int alturaLaser, colunaMestre;
  int iteracao, linha, coluna, aux, mover;
  int atualizarLaser;


  scanf("%d", &dimensao);
  scanf("%d %d", &linha1, &coluna1);
  scanf("%d %d", &linha2, &coluna2);
  scanf("%d %d", &linha3, &coluna3);
  scanf("%d %d", &linha4, &coluna4);
  scanf("%d %d", &linha5, &coluna5);
  scanf("%d", &colunaMestre);

  alturaLaser = dimensao-1;
  iteracao = 0;

  /* Iterar 10 vezes */
  do{
    /* Escrever configuracao atual  */
    for(linha = 1; linha <= dimensao; linha++){
	for(coluna = 1; coluna <= dimensao ; coluna++){

	/* Escreve Inimigos  */
	if((coluna == coluna1 && linha == linha1) ||
	   (coluna == coluna2 && linha == linha2) ||
	   (coluna == coluna3 && linha == linha3) ||
	   (coluna == coluna4 && linha == linha4) ||
	   (coluna == coluna5 && linha == linha5)){
	  printf("* ");
	  
	  /* Escreve Laser  */
	}else if(coluna == colunaMestre && 
		 linha > alturaLaser && 
		 linha != dimensao){
	  printf("| ");
	  
	  /* Escreve Posicao Atirador  */
	}else if(coluna == colunaMestre && 
		 linha == dimensao){
	  printf("X ");

	  /* Escreve Espaços em Branco  */
	}else {
	  printf(". ");
	}
	 
      }
      printf("\n");
    }
    printf("\n");
    
    /* Adiciona na nova iteracao  */
    atualizarLaser = -1;
    iteracao++;

    /* Subir laser  */
    if(alturaLaser > 0){
      alturaLaser--;
    }

    /* Calcular zig-zag */
    aux = iteracao % 4;
    if(aux == 1 || aux == 0){
      mover = +1;
    }
    if(aux == 2 || aux == 3){
      mover = -1;
    }

    /* Andar com Inimigos 1*/
    aux = coluna1 + mover;
    if((aux >=1 && aux <= dimensao) &&
       !((aux == coluna2+mover && linha1 == linha2)) &&
       !((aux == coluna3+mover && linha1 == linha3)) &&
       !((aux == coluna4+mover && linha1 == linha4)) &&
       !((aux == coluna5+mover && linha1 == linha5))){
      coluna1 = aux;
    }
      
    /* Andar com Inimigos 2*/
    aux = coluna2 + mover;
    if((aux >=1 && aux <= dimensao) &&
       !((aux == coluna1 && linha2 == linha1)) &&
       !((aux == coluna3+mover && linha2 == linha3)) &&
       !((aux == coluna4+mover && linha2 == linha4)) &&
       !((aux == coluna5+mover && linha2 == linha5))){
      coluna2 = aux;
    }
 

    /* Andar com Inimigos 3*/
    aux = coluna3 + mover;
    if((aux >=1 && aux <= dimensao) &&
       !((aux == coluna1 && linha3 == linha1)) &&
       !((aux == coluna2 && linha3 == linha2)) &&
       !((aux == coluna4+mover && linha3 == linha4)) &&
       !((aux == coluna5+mover && linha3 == linha5))){
      coluna3 = aux;
    }
      
  
    /* Andar com Inimigos 4*/
    aux = coluna4 + mover;
    if((aux >=1 && aux <= dimensao) &&
       !((aux == coluna1 && linha4 == linha1)) &&
       !((aux == coluna2 && linha4 == linha2)) &&
       !((aux == coluna3 && linha4 == linha3)) &&
       !((aux == coluna5+mover && linha4 == linha5))){
      coluna4 = aux;
    }
      
    /* Andar com Inimigos 5*/
    aux = coluna5 + mover;
    if((aux >=1 && aux <= dimensao) &&
       !((aux == coluna1 && linha5 == linha1)) &&
       !((aux == coluna2 && linha5 == linha2)) &&
       !((aux == coluna3 && linha5 == linha3)) &&
       !((aux == coluna4 && linha5 == linha4))){
      coluna5 = aux;
    }

    if(linha1 > alturaLaser && coluna1 == colunaMestre){
      if(linha1 > atualizarLaser){
	atualizarLaser = linha1;
      }
      coluna1 = -1;
      linha1 = -1;
    }
     
    if(linha2 > alturaLaser && coluna2 == colunaMestre){
      if(linha2 > atualizarLaser){
	atualizarLaser = linha2;
      }
      coluna2 = -1;
      linha2 = -1;
    }

    if(linha3 > alturaLaser && coluna3 == colunaMestre){
      if(linha3 > atualizarLaser){
	atualizarLaser = linha3;
      }
      coluna3 = -1;
      linha3 = -1;
    }

    if(linha4 > alturaLaser && coluna4 == colunaMestre){
      if(linha4 > atualizarLaser){
	atualizarLaser = linha4;
      }
      coluna4 = -1;
      linha4 = -1;
    }

    if(linha5 > alturaLaser && coluna5 == colunaMestre){
      if(linha5 > atualizarLaser){
	atualizarLaser = linha5;
      }
      coluna5 = -1;
      linha5 = -1;
    }

    /* Se algum foi atingido atualizar laser  */
    if(atualizarLaser != -1){
      alturaLaser = atualizarLaser; 
    }
    
  }while(iteracao < 10);
  
  return 0;
}
