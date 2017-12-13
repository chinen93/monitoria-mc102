/*
  Pedro Chinen - 175828
  Laboratório 09 - A entrada do meu programa é um programa?


  Para este laboratório, poderão ser utilizadas apenas variáveis
  simples, vetores, matrizes, operações de entrada e saída, operações
  aritméticas, desvios condicionais, estruturas de repetição, strings,
  funções e apontadores


  Entrada:
  N > 1, número de linhas do programa quer será interpretada
  N linhas contendo as instruções

  MAXIMO de 150 instruções
  COMENTARIOS começando com # não são contados como instruções
  NUMERO MAXIMO de registradores = 12

  Para esta atividade não é permitido o uso de colchetes para acessar
  elementos de vetores ou matrizes. Você deve utilizar apontadores de
  forma explícita para isso.



 */

#include <stdio.h>
#include <string.h>
#include "lab09.h"
#define MAX_CHAR 50

/* Implementa instrução MOV
 *
 * Recebe dois apontadores para registradores e um apontador para o
 * Program Counter 
 *
 * Não retorna nada
 */
void mov(int *rd, int *ro, int *pc){
  *rd = *ro;
  *pc = *pc+1;
}

/* Implementa instrução MOC
 * 
 * Recebe um apontador para um registrador,
 * um inteiro n e um apontador para o Program Counter
 *
 * Não retorna nada
 */
void moc(int *rd, int n, int *pc){
  *rd = n;
  *pc = *pc+1;
}

/* Implementa instrução ADD
 *
 * Recebe dois apontadores para registradores e um apontador para o
 * Program Counter 
 *
 * Não retorna nada
 */
void add(int *rd, int *ro, int *pc){
  *rd = *rd + *ro;
  *pc = *pc + 1;
}

/* Implementa instrução ADC
 *
 * Recebe um apontador para um registrador, um inteiro n e um
 * apontador para o Program Counter 
 *
 * Não retorna nada
 */
void adc(int *rd, int n, int *pc){
  *rd = *rd + n;
  *pc = *pc + 1;
}

/* Implementa instrução SUB
 *
 * Recebe dois apontadores para registradores e um apontador para o
 * Program Counter 
 *
 * Não retorna nada
 */
void sub(int *rd, int *ro, int *pc){
  *rd = *rd - *ro;
  *pc = *pc + 1;
}

/* Implementa instrução SUC
 *
 * Recebe um apontador para um registrador, um inteiro n e um
 * apontador para o Program Counter
 *
 * Não retorna nada
 */
void suc(int *rd, int n, int *pc){
  *rd = *rd - n;
  *pc = *pc + 1;
}

/* Implementa instrução JMP
 *
 * Recebe um apontador para um registrador, um inteiro n e um
 * apontador para o Program Counter
 *
 * Não retorna nada
 */
void jmp(int *rd, int n, int *pc){
  if(*rd >= 0){
    *pc = *pc + n;
  }else{
    *pc = *pc + 1;
  }
}

/* Implementa instrução PTC
 *
 * Recebe um inteiro valor e um apontador para o Program Counter
 *
 * Não retorna nada
 */
void ptc(int valor, int *pc){
  printf("%c", valor);
  *pc = *pc + 1;
}

/* Implementa instrução PTN
 *
 * Recebe um inteiro valor e um apontador para o Program Counter
 *
 * Não retorna nada
 */
void ptn(int valor, int *pc){
  printf("%d ", valor);
  *pc = *pc + 1;  
}

int getInteger(char string[]){
  int retorno = 0;
  sscanf(string, "%d\n", &retorno);
  return retorno;
}

int main(){
  

  int n;
  char entrada[MAX_CHAR];
  char instrucoes[MAX_PROGRAMA][MAX_CHAR];
  char *ponteiro;
  int pc = 0;
  int reg[N_REGISTRADORES];
  char inst[N_INSTRUCOES][4] = INSTRUCOES;
  char comando[4];
  char param1[4], param2[4];
  int *p1 = NULL; 
  int *p2 = NULL; 
  int i, j, numInstrucao = 0, opcao, numParam;
  
  /* Ler quantidade de comandos passados */
  scanf("%d\n", &n);

  /* Ler instrucoes */
  for(i = 0; i < n; i ++){

    /* Ler todas os comandos */
    fgets(entrada, MAX_CHAR, stdin);
    scanf("\n");

    /* Verificar se eh uma instrucao valida, primeira letra != # */
    if(*entrada != '#'){
      /* Colocar no vetor de instrucoes */

      strcpy(*instrucoes+numInstrucao*MAX_CHAR,entrada);
      numInstrucao++;
    }
  }

  /* Enquanto pc < numInstrucao faça */
  while(pc < numInstrucao){   

    /* Pegar entrada guardada */    
    strcpy(entrada, *instrucoes+pc*MAX_CHAR);

    /* Separa os comandos dos parametros */
    j = 0;
    opcao = 0;
    for(i = 0; *(entrada+i) != '\0'; i++){

      ponteiro = (entrada+i);
      /* pegar comando na posicao pc */
      if(*ponteiro != ' ' && *ponteiro != '\n'){
        if(opcao == 0){
          *(comando+j) = *ponteiro;
        }else if(opcao == 1){
          *(param1+j) = *ponteiro;
        }else if(opcao == 2){
          *(param2+j) = *ponteiro; 
        }
        j++;
      }else{
        if(opcao == 0){
          *(comando+j) = '\0';
        }else if(opcao == 1){
          *(param1+j) = '\0';
        }else if(opcao == 2){
          *(param2+j) = '\0';
        }        
        j = 0;
        opcao++;
      }
    }

    /* Pega o valor inteiro que esta na string */
    if(*param1 == 'R'){
      numParam = getInteger((param1+1));
      p1 = (reg+numParam);
    }else{
      numParam = getInteger(param1);
      *p1 = numParam;
    }
    
    /* Pega o valor inteiro que esta na string */
    if(*param2 == 'R'){
      numParam = getInteger((param2+1));
      p2 = (reg+numParam);
    }else{
      numParam = getInteger(param2);
      p2 = &numParam;
    }

    /* Executa o comando com os parametros desejados*/
    if(strncmp(comando, *(inst+0), sizeof(comando)) == 0){
      /* MOV */
      mov(p1, p2, &pc);
    }
    if(strncmp(comando, *(inst+1), sizeof(comando)) == 0){
      /* MOC */
      moc(p1, *p2, &pc);
    }
    if(strncmp(comando, *(inst+2), sizeof(comando)) == 0){
      /* ADD */
      add(p1, p2, &pc);
    }
    if(strncmp(comando, *(inst+3), sizeof(comando)) == 0){
      /* ADC */
      adc(p1, *p2, &pc);
    }
    if(strncmp(comando, *(inst+4), sizeof(comando)) == 0){
      /* SUB */
      sub(p1, p2, &pc);
    }
    if(strncmp(comando, *(inst+5), sizeof(comando)) == 0){
      /* SUC */
      suc(p1, *p2, &pc);
    }
    if(strncmp(comando, *(inst+6), sizeof(comando)) == 0){
      /* JMP */
      jmp(p1, *p2, &pc);
    }
    if(strncmp(comando, *(inst+7), sizeof(comando)) == 0){
      /* PTN */
      ptn(*p1, &pc);
    }
    if(strncmp(comando, *(inst+8), sizeof(comando)) == 0){
      /* PTC */
      ptc(*p1, &pc);
    }
  }
  printf("\n");

  return 0;
}
