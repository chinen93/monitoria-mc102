/*
  Pedro Hideaki Uiechi Chinen
  Laboratorio 10

 Implementar um programa que:

    receba, como entrada, tanto as tabelas musicais com os trechos de
    música que serão tocados quanto as informações sobre quais trechos
    devem ser tocados em cada canal, com que timbre sonoro e em qual
    ordem;

    produza, como saída, os eventos ordenados que permitirão a
    realização mecânica da música. As sequências de todos os canais
    empregados devem começar simultaneamente.


 Para este laboratório, poderão ser utilizadas apenas variáveis
 simples, operações de entrada e saída, operações aritméticas, desvios
 condicionais, estruturas de repetição, vetores, matrizes, strings,
 funções, apontadores e registros


 i <- numero de canais usados na instancia
 i-numeros [1:128] timbre de cada canal
 j <- numero de trechos presentes na sequencia de cada canal
 k <- numero de trechos na tabela musical
 2 * k-linhas
 1 linha <- 3 valores : indentificador do trecho, 
                         intensidade das nota, 
                         numero de notas ou pausas do trecho
 2 linha <- sequencia de notas ou pausas 2 numeros: duracao da nota,
                                                    frequencia da nota
          
 i-linhas com j numeros : sequencia de trechos que compoe o canal


*/

#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

typedef struct{
  int duracao;
  int freq;
} Nota;

typedef struct{
  int intensidade;
  int qtdNotasNaoPausa;
  int qtdNotas;
  Nota **notas;
} Trecho;

typedef struct{
  int numTrechos;
  int *trechos;
  int numNotas;
  Nota **notas;
  int timbre;
  int deltaTime;
  int indiceNota;
} Canal;


void saida(char modo, 
	   int numCanais, 
	   unsigned short int *canais, 
	   int numEventos, 
	   TpEvento *eventos){

}

void criarTabelaMusica(int numTrechosTabelaMusica, Trecho** vetorTrechos){
  Trecho* trecho;
  int identificadorTrecho;
  int intensidadeTrecho;
  int qtdNotas;
  int i, j, dur, freq;
  Nota* nota;

 /* Criar a tabela de musica */
  for(i=0; i < numTrechosTabelaMusica; i++){
    /* Ler identificador do trecho, intensidade, qtdNotas */
    scanf("%d %d %d", &identificadorTrecho, &intensidadeTrecho, &qtdNotas);

    /* Instanciar Trecho com quantidade de notas */
    trecho =  malloc(sizeof(Trecho));
    trecho->intensidade = intensidadeTrecho;
    trecho->qtdNotas = qtdNotas;
    trecho->qtdNotasNaoPausa = 0;
    trecho->notas = malloc(sizeof(Nota) * qtdNotas);

    /* Ler Notas e colocar no vetor de notas do trecho */
    for(j=0; j<qtdNotas; j++){
      nota = malloc(sizeof(Nota));

      scanf("%d %d", &dur, &freq);
      nota->duracao = dur;
      nota->freq = freq;

      trecho->notas[j] = nota;
      
      if(nota->freq != 128){
        trecho->qtdNotasNaoPausa++;
      }
    }

    /* Colocar no vetor de trechos na posicao do identificador do trecho  */
    /* o trecho instanciado */
    vetorTrechos[i] = trecho;
  }
}

void deletarTabelaMusica(int numTrechosTabelaMusica, Trecho** vetorTrechos){
  int i,j;

  for(i = 0; i < numTrechosTabelaMusica; i++){
    for(j = 0; j < vetorTrechos[i]->qtdNotas; j++){
      free(vetorTrechos[i]->notas[j]);
    }
    free(vetorTrechos[i]);
  }

  free(vetorTrechos);
}

void criarCanais(int numCanais, Canal **vetorCanais){
  int i;
  Canal *canal;
  int timbre;
  
  for(i = 0; i < numCanais; i++){
    scanf("%d", &timbre);
    canal = malloc(sizeof(Canal));
    canal->timbre = timbre;
    canal->numTrechos = 0;
    canal->numNotas = 0;
    canal->deltaTime = 0;
    canal->indiceNota = 0;
    vetorCanais[i] = canal;
  }
}

int lerCanais(int numCanais, int numTrechosPorCanal, 
              Canal **vetorCanais, Trecho **vetorTrechos){

  int i, j, k, l;
  int identificadorTrecho;
  int numEventos = 0;
  Nota *nota, *aux;

  /* Colocar no vetor os indicadores dos trechos */
  for(i = 0; i < numCanais; i++){
    vetorCanais[i]->numNotas = 0;

    vetorCanais[i]->numTrechos = numTrechosPorCanal;
    vetorCanais[i]->trechos = malloc(sizeof(int) * numTrechosPorCanal);

    for(j=0; j < numTrechosPorCanal; j++){
      scanf("%d", &identificadorTrecho);

      identificadorTrecho -= 1;

      vetorCanais[i]->trechos[j] = identificadorTrecho;

      vetorCanais[i]->numNotas += vetorTrechos[identificadorTrecho]->qtdNotas;

      numEventos += (vetorTrechos[identificadorTrecho]->qtdNotasNaoPausa) * 2;
    }

    vetorCanais[i]->notas = malloc(sizeof(Nota) * vetorCanais[i]->numNotas);

    for(j=0, l=0; j < vetorCanais[i]->numTrechos; j++){
      identificadorTrecho = vetorCanais[i]->trechos[j];

      for(k=0; k < vetorTrechos[identificadorTrecho]->qtdNotas; k++){
        nota = vetorTrechos[identificadorTrecho]->notas[k];

        aux = malloc(sizeof(Nota));
        aux->duracao = nota->duracao;
        aux->freq = nota->freq;

        vetorCanais[i]->notas[l] = aux;
        l++;
      }
    }
  }
  return numEventos;
}

void deletarCanais(int numCanais, Canal **vetorCanais){
    int i, j;

  for(i = 0; i < numCanais; i++){
    free(vetorCanais[i]->trechos);
    for(j = 0; j < vetorCanais[i]->numNotas; j++){
      free(vetorCanais[i]->notas[j]);
    }
    free(vetorCanais[i]);
  }

  free(vetorCanais);
}

int main(){

  int numCanais, numEventos = 0;
  TpEvento *vetorEventos;
  int numTrechosPorCanal, numTrechosTabelaMusica;
  Trecho **vetorTrechos;
  Canal **vetorCanais;
  int i, j;
  int deltaTime = 0;
  int lastTime = -1;

  /* Ler numero de canais */
  scanf("%d", &numCanais);
  
  vetorCanais = malloc(sizeof(Canal) * numCanais);
  criarCanais(numCanais, vetorCanais);
  
  /* Ler numero de trechos por canal, e numero de trechos na tabela de
     musica */
  scanf("%d %d", &numTrechosPorCanal, &numTrechosTabelaMusica);
  
  /* Criar vetor de trechos com tamanho K */
  vetorTrechos = malloc(sizeof(Trecho) * numTrechosTabelaMusica);

  criarTabelaMusica(numTrechosTabelaMusica, vetorTrechos);

  printf("%d\n", numTrechosTabelaMusica);
  for(i = 0; i<numTrechosTabelaMusica; i++){
    printf("%d %d %d [%d]\n", 
           i, 
           vetorTrechos[i]->intensidade, 
           vetorTrechos[i]->qtdNotas,
           vetorTrechos[i]->qtdNotasNaoPausa);
    for(j = 0; j<vetorTrechos[i]->qtdNotas; j++){
      printf("%d %d\n", 
             vetorTrechos[i]->notas[j]->duracao,
             vetorTrechos[i]->notas[j]->freq);    
    }
    printf("===============================\n");
  }

  /* Criar N canais sequencias de trechos com tamanho j */
 
  numEventos = lerCanais(numCanais, numTrechosPorCanal, 
                         vetorCanais, vetorTrechos);

  for(i = 0; i < numCanais; i++){
    printf("[");
    for(j=0; j<numTrechosPorCanal; j++){
      printf("%d ", vetorCanais[i]->trechos[j]);
    }
    printf("] -> %d\n", vetorCanais[i]->numNotas);    
    for(j=0; j<vetorCanais[i]->numNotas; j++){
      printf("(%d %d)\n",
             vetorCanais[i]->notas[j]->duracao,
             vetorCanais[i]->notas[j]->freq);
    }
    printf("---------\n");
  }

  printf("(%d)\n", numEventos);

  vetorEventos = malloc(sizeof(TpEvento) * numEventos);


  
  

  /* Criando um vetor de TpEventos */
  /* Cada nota tem 2 TpEventos, um de inicio e um de final (velocity = 0) */

  /* deltaTime = 0 significa que esse TpEvento começa junto com o
     primeiro TpEvento que não tem 0 nas posições anteriores a ele no
     vetor */

  /* dois primeiros juntos */
  /* tres depois tambem juntos */
  /* [0,0,18,0,0] */

  /* ------------------------------------------------ */
  /* Dar free nas coisas que eu usei */
  deletarTabelaMusica(numTrechosTabelaMusica, vetorTrechos);

  deletarCanais(numCanais, vetorCanais);

  free(vetorEventos);
  /* ------------------------------------------------ */


  return 0;
}
