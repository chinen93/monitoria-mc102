/*
  Pedro Hideaki Uiechi Chinen RA:175828


  Entrada: Cada linha representa as informações para um som a ser reproduzido

  - Numero de [1..128] == instrumento que deve produzir o som
  - Numero [0..127] == da nota que o som deve ter
  - A intensidade [1..127] com que o som deve soar
  - O instante de tempo em que o som deve ser iniciado
  - Duração de tempo em que o som deve ser mantido


  Saida: 
  chamar a função
  saida(int modo, int numEventos, tpEvento eventos[])
  
  modo == 0
  numEventos == numero total de eventos
  vetor de tpEventos

 */

#include "lab10.h"
#include <stdlib.h>

void inicializarEvento (TpEvento *tp, 
                        int instrumento,
                        int nota,
                        int intensidade,
                        int instante){
  tp->instrumento = instrumento;
  tp->nota = nota;
  tp->intensidade = intensidade;
  tp->instante = instante;
}

TpEvento *lerNota(){
  TpEvento *tp = NULL;
  int instante, instrumento, nota, intensidade, duracao;

  scanf("%d %d %d %d %d\n", 
        &instrumento, 
        &nota, 
        &intensidade, 
        &instante, 
        &duracao);

  if(instrumento != 0 &&
     duracao != 0){

    tp = malloc(sizeof(TpEvento) * 2);
    
    inicializarEvento(&tp[0], instrumento, nota, intensidade, instante);
    inicializarEvento(&tp[1], instrumento, nota, 0, instante+duracao);
  }

  return tp;
}

void freeTpEvento(TpEvento *tp){
  free(tp);
}

void swap(TpEvento *a, TpEvento *b){
  TpEvento *aux;
  aux = malloc(sizeof(TpEvento));

  inicializarEvento(aux, 
                    a->instrumento, 
                    a->nota, 
                    a->intensidade, 
                    a->instante);

  inicializarEvento(a, 
                    b->instrumento, 
                    b->nota, 
                    b->intensidade, 
                    b->instante);

  inicializarEvento(b, 
                    aux->instrumento, 
                    aux->nota, 
                    aux->intensidade, 
                    aux->instante);

  freeTpEvento(aux);
}

void bubbleSort(TpEvento *eventos, int qtdEventos)
{
  long iCorreto, iIncorreto;
 
  for (iCorreto = 0 ; iCorreto < ( qtdEventos - 1 ); iCorreto++){
    for (iIncorreto = 0 ; iIncorreto < qtdEventos - iCorreto - 1; iIncorreto++){
      if (eventos[iIncorreto].instante > eventos[iIncorreto+1].instante){ 
        swap(&eventos[iIncorreto], &eventos[iIncorreto+1]);
      }
      if (eventos[iIncorreto].instante == eventos[iIncorreto+1].instante &&
          eventos[iIncorreto].instrumento > eventos[iIncorreto+1].instrumento){ 
        swap(&eventos[iIncorreto], &eventos[iIncorreto+1]);
      }
      if (eventos[iIncorreto].instante == eventos[iIncorreto+1].instante &&
          eventos[iIncorreto].instrumento == eventos[iIncorreto+1].instrumento && 
          eventos[iIncorreto].nota > eventos[iIncorreto+1].nota){ 
        swap(&eventos[iIncorreto], &eventos[iIncorreto+1]);
      }
      if (eventos[iIncorreto].instante == eventos[iIncorreto+1].instante &&
          eventos[iIncorreto].instrumento == eventos[iIncorreto+1].instrumento && 
          eventos[iIncorreto].nota == eventos[iIncorreto+1].nota &&
          eventos[iIncorreto].intensidade > eventos[iIncorreto+1].intensidade){ 
        swap(&eventos[iIncorreto], &eventos[iIncorreto+1]);
      }
    }
  }
}

int main(){
  int qtdEventos = 0, indice = 0;
  TpEvento *nota, *eventos;

  eventos = malloc(sizeof(TpEvento) * qtdEventos);

  nota = lerNota();

  while(nota != NULL){
    qtdEventos += 2;

    eventos = realloc(eventos, sizeof(TpEvento) * qtdEventos);

    eventos[indice].instrumento = nota[0].instrumento;
    eventos[indice].nota = nota[0].nota;
    eventos[indice].intensidade = nota[0].intensidade;
    eventos[indice].instante = nota[0].instante;

    indice++;

    eventos[indice].instrumento = nota[1].instrumento;
    eventos[indice].nota = nota[1].nota;
    eventos[indice].intensidade = nota[1].intensidade;
    eventos[indice].instante = nota[1].instante;

    indice++;

    freeTpEvento(nota);
    nota = lerNota();
  }

  bubbleSort(eventos, qtdEventos);

  saida(0, qtdEventos, eventos);

  freeTpEvento(eventos);
  
  return 0;
}
