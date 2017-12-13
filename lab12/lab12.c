/* 

   Pedro Hideaki Uiechi Chinen RA:175828

   Laboratório 12 - Labirinto

   Tarefa: Percorrer o labirinto de fora para dentro. As muralhas do
   labirinto são circulares e existem barreiras em seus corredores.

   Entrada:
   número de muralhas -> n
   (2n-1) proximas linhas:
   - angulo de passagem na muralha
   - angulo de barreiras no corredor

   angulos = [0..359]

   Saida:
   Caminhos entre as muralhas até o meio do labirinto
   E angulo = se passou de uma muralha externa para uma interna
   S angulo = se passou de uma muralha interna para uma externa

   Serão no máximo 10 muralhas a atravessar
 */

#include <stdio.h>

#define MAX 30
#define MAXCAMINHO 100
#define MAXANGULO 360
#define MAXSTRING 100


int abs(int x);
int temCaminho(int abertura,
               int angulo, 
               int numBarreiras[MAX], 
               int barreiras[MAX][MAXANGULO],
               int passos);
int acharPassagem(int passos,
                  int numPassagem[MAX],
                  int *numCaminho,
                  int angulo,
                  int numBarreiras[MAX],
                  int passagem[MAX][MAXANGULO],
                  int barreiras[MAX][MAXANGULO],
                  int caminho[MAXCAMINHO],
                  int muralha,
                  int dentro);
int acharCentro(int passagem[MAX][MAXANGULO], 
		int barreiras[MAX][MAXANGULO],
		int numPassagem[MAX],
		int numBarreiras[MAX],
		int muralha,
		int passos,
		int angulo,
		int *numCaminho,
		int caminho[MAXCAMINHO]);


int abs(int x){
  int y;

  if(x < 0)
    y = -x;
  else
    y = x;

  return y;
}

int temCaminho(int abertura,
               int angulo, 
               int numBarreiras[MAX], 
               int barreiras[MAX][MAXANGULO],
               int passos){

  int j, aux;
  int usarPassagemHorario = 1;
  int usarPassagemAntiHorario = 1;
  int horario, antihorario;
  int barreiraHorario, barreiraAntihorario;
  int barreira;

  usarPassagemHorario = 1;
  usarPassagemAntiHorario = 1;

  /* printf("passos = %d\n", passos); */

  /* Verifica se a passagem não esta obstruida por barreiras */
  for(j=0; 
      j < numBarreiras[passos-1] &&
        (usarPassagemHorario == 1 ||
         usarPassagemAntiHorario == 1);
      j++){

    barreira = barreiras[passos-1][j];

    /* printf("barreira = %d\n", barreira); */
    /* printf("abertura = %d\n", abertura); */
    /* printf("angulo = %d\n", angulo); */


    if(abertura >= angulo){
      horario = abs(angulo + (MAXANGULO-abertura));
      antihorario = abs(abertura - angulo);
    }else{
      horario = abs(abertura - angulo);
      antihorario = abs((abertura + MAXANGULO) - angulo);
    }

    if(barreira >= angulo){
      barreiraHorario = abs(angulo + (MAXANGULO-barreira));
      barreiraAntihorario = abs(barreira - angulo);
    }else{
      barreiraHorario = abs(barreira - angulo );
      barreiraAntihorario = abs((barreira + MAXANGULO) - angulo);
    }

    /* printf("[%d %d][%d %d]\n", */
    /*        horario, */
    /*        antihorario, */
    /*        barreiraHorario, */
    /*        barreiraAntihorario); */

    if(horario < barreiraHorario){
      usarPassagemHorario = 0;
    }

    if(antihorario < barreiraAntihorario){
      usarPassagemAntiHorario = 0;
    }

    /* printf("[%d %d]\n", usarPassagemHorario, usarPassagemAntiHorario); */
  }

  /* Ver o que fazer quando passa de uma volta completa */
  /* printf("[%d / %d]\n",  */
  /*        usarPassagemHorario,  */
  /*        usarPassagemAntiHorario); */

  if(usarPassagemHorario == 1 || usarPassagemAntiHorario == 1){
    aux = 1;
  }else{
    aux = 0;
  }

  return aux;

}

int acharPassagem(int passos,
                  int numPassagem[MAX],
                  int *numCaminho,
                  int angulo,
                  int numBarreiras[MAX],
                  int passagem[MAX][MAXANGULO],
                  int barreiras[MAX][MAXANGULO],
                  int caminho[MAXCAMINHO],
                  int muralha,
                  int dentro){
  int i, andar;
  int terminou = 0;
  int abertura;

  /* Percorrer todas as passagens para a muralha*/
  for(i=0; i<numPassagem[passos] && terminou == 0; i++){

    abertura = passagem[passos][i];

    /* printf("%d %d %d %d------\n",  */
    /*        passos,  */
    /*        numPassagem[passos-2],  */
    /*        numBarreiras[passos-3], */
    /*        *numCaminho); */

    /* Verificar se tem uma barreira no caminho ate a passagem */
    if(*numCaminho > 0){

      andar = temCaminho(abertura,
                         angulo, 
                         numBarreiras, 
                         barreiras,
                         passos);
    }else{
      andar = 1;
    }

    /* Verifica se da para passar pela passagem*/
    if(andar == 1){

      /* Caminho funciona entao colocar ele no vetor de caminho */
      caminho[*numCaminho] = passagem[passos][i];
      angulo = passagem[passos][i];

      /* Andar para o proximo valor que tem passagem */
      if(dentro == 1){
        passos+=2;
        muralha-=1;
      }else{
        passos-=2;
        muralha+=1;
      }

      (*numCaminho)++;

      /* Chamar a funcao recursivamente */
      terminou = acharCentro(passagem, barreiras, numPassagem, numBarreiras, 
			     muralha, passos, angulo, 
			     numCaminho, caminho);
    }
  }


  return terminou;
}


int acharCentro(int passagem[MAX][MAXANGULO], 
		int barreiras[MAX][MAXANGULO],
		int numPassagem[MAX],
		int numBarreiras[MAX],
		int muralha,
		int passos,
		int angulo,
		int *numCaminho,
		int caminho[MAXCAMINHO]){
  int i;
  int terminou = 0;
  int abertura, andar;

  /* printf("==============\n"); */
  /* printf("%d %d %d %d\n", muralha, passos, *numCaminho, angulo); */

  /* Se chegou no meio do labirinto, retornar o numero de passos dado */
  if(muralha == 0){
    terminou = 1;
    return terminou;
  }

  /* for(i=0; i<numPassagem[passos]; i++){ */
  /*   printf("(%d) ", passagem[passos][i]); */
  /* } */
  /* printf("\n");  */
  /* for(i=0; i<numBarreiras[passos-1]; i++){ */
  /*   printf("(%d) ", barreiras[passos-1][i]); */
  /* } */
  /* printf("\n");  */

  /* Percorrer todas as passagens para a proxima muralha */
  
  for(i=0; i<numPassagem[passos] && terminou == 0; i++){

    abertura = passagem[passos][i];

    /* printf("%d %d %d %d------\n",  */
    /*        passos,  */
    /*        numPassagem[passos],  */
    /*        numBarreiras[passos-1], */
    /*        *numCaminho); */

    /* Verificar se tem uma barreira no caminho ate a passagem */
    if(*numCaminho > 0){

      andar = temCaminho(abertura,
                         angulo,
                         numBarreiras,
                         barreiras,
                         passos);
    }else{
      andar = 1;
    }

    /* Verifica se da para passar pela passagem*/
    if(andar == 1){

      /* Caminho funciona entao colocar ele no vetor de caminho */
      caminho[*numCaminho] = passagem[passos][i];
      angulo = passagem[passos][i];

      /* Andar para o proximo valor que tem passagem */
      passos+=2;
      (*numCaminho)++;

      /* Chamar a funcao recursivamente */
      terminou = acharCentro(passagem, barreiras, numPassagem, numBarreiras,
        		     muralha-1, passos, angulo,
        		     numCaminho, caminho);
    }
  }

  /* Percorrer todas as passagens para a muralha anterior*/
  for(i=0; passos > 2 && i<numPassagem[passos-2] && terminou == 0; i++){

    abertura = passagem[passos-2][i];

    /* printf("%d %d %d %d------\n",  */
    /*        passos,  */
    /*        numPassagem[passos-2],  */
    /*        numBarreiras[passos-3], */
    /*        *numCaminho); */

    /* Verificar se tem uma barreira no caminho ate a passagem */
    if(*numCaminho > 0){

      andar = temCaminho(abertura,
                        angulo, 
                        numBarreiras, 
                        barreiras,
                        passos);
    }else{
      andar = 1;
    }

    /* Verifica se da para passar pela passagem*/
    if(andar == 1){

      /* Caminho funciona entao colocar ele no vetor de caminho */
      caminho[*numCaminho] = passagem[passos-2][i];
      angulo = passagem[passos-2][i];

      /* Andar para o proximo valor que tem passagem */
      passos-=2;
      (*numCaminho)++;

      /* Chamar a funcao recursivamente */
      terminou = acharCentro(passagem, barreiras, numPassagem, numBarreiras, 
			     muralha+1, passos, angulo, 
			     numCaminho, caminho);
    }
  }


  return terminou;
}

int proxNumero(char string[MAXSTRING], int pos, int *numero){
  int posicao = -1;
  char aux[4];
  int i, j;

  /* Anda na string ate chegar no proximo espaço ou ao final da frase */
  for(i=pos, j=0; 
      string[i] != ' ' && string[i] != '\0'; 
      i++, j++){

    /* Colocando o caracter num auxiliar */
    aux[j] = string[i];
  }

  /* Ao chegar no final colocar o caracter de final de string no auxiliar */
  aux[j] = '\0';
  
  /* Pegar o numero que esta na string auxiliar */
  sscanf(aux, "%d", numero);
  
  /* Retornar a proxima posicao que tem um numero */
  if(string[i] == '\0'){
    posicao = -1;
  }else{
    posicao = i+1;
  }

  return posicao;
}

int main(){
  int numMuralhas;
  int passagem[MAX][MAXANGULO];
  int numPassagem[MAX];
  int barreiras[MAX][MAXANGULO];
  int numBarreiras[MAX];
  int passos = 0;
  int caminho[MAXCAMINHO];
  int qtdPassos = 0;
  int i, j, numero, posicao, numTotal;
  char aux[MAXSTRING];

  scanf("%d\n", &numMuralhas);
  numTotal = (numMuralhas*2)-1;

  for(i=0; i<MAX; i++){
    for(j=0; j<MAXANGULO; j++){
      passagem[i][j] = 0;
      barreiras[i][j] = 0;
    }
    numPassagem[i] = 0;
    numBarreiras[i] = 0;
  }

  for(i=0, j=0; i<numTotal; i++, j++){
      fgets(aux, 100, stdin);
      posicao = 0;
      while(posicao >= 0){
	posicao = proxNumero(aux, posicao, &numero);
	/* printf("[%d] ", numero); */

	if(i % 2 == 0){
	  passagem[i][numPassagem[j]] = numero;
	  numPassagem[j]++;
	}else{
	  barreiras[i][numBarreiras[j]] = numero;
	  numBarreiras[j]++;
	}

      }
      /* printf("\n");       */
  }

  /* printf("------------------------\n");       */
  /* for(i=0; i<numTotal; i++){ */
  /*   printf("[%d %d]\n", numPassagem[i], numBarreiras[i]); */
  /*   printf("---\n");       */
  /*   for(j=0; j<numPassagem[i]; j++){ */
  /*     printf("[%d]", passagem[i][j]); */
  /*   } */
  /*   printf("\n");       */
  /*   printf("---\n");       */
  /*   for(j=0; j<numBarreiras[i]; j++){ */
  /*     printf("(%d)", barreiras[i][j]); */
  /*   } */
  /*   printf("\n"); */
  /*   printf("---\n");       */
  /* } */
  /* printf("------------------------\n");    */   

  acharCentro(passagem, barreiras, numPassagem, numBarreiras,
                         numMuralhas, passos, 0,
                         &qtdPassos, caminho);

  for(i=0; i<qtdPassos; i++){
    printf("[%d]", caminho[i]);
  }
  printf("\n");

  return 0;
}
