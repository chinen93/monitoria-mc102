/*
  Pedro Hideaki Uiechi Chinen RA: 175828

  Laboratório 07: Hipótese de Sapir–Whorf


  Os marcadores temporais que serão utilizados são os seguintes:
  ontem, hoje, amanhã, agora, logo, cedo, tarde, breve, nunca, sempre,
  jamais.
  
  A entrada do seu programa é composta por:
  - Número de frases N
  - N frases
  - Número de palavras de Busca P
  - P palavras de busca
  
  Saida:
  - palavra de busca relacionado com o marcador temporal que mais se relaciona
  - vetor de palavras e a quantidade de vezes que elas aparecem no texto


  relacionamento entre marcador temporal e palavra de busca :
  (ocorrencia_simultanea*100)/total_ocorrencia

  sendo ocorrencia_simultanea eh a quantidade de vezes que a palavra
  de busca ocorre na mesma FRASE que o marcador temporal

  E o total_ocorrencia a quantidade de vezes que a palavra de busca
  ocorre no TEXTO
  

  - Uma palavra tem no máximo 20 caracteres.  
  - Uma frase tem no máximo 250 caracteres.  
  - Um texto de entrada tem no máximo 50 frases e 250 palavras.

  para este laboratório, poderão ser utilizadas apenas variáveis
  simples, vetores, matrizes, operações de entrada e saída, operações
  aritméticas, desvios condicionais, estruturas de repetição, strings
  e funções

*/


#include <stdio.h>
#include <string.h>
#include "lab07.h"


/* Funções a serem implementadas */

/* Objetivo: função que extrai a próxima palavra da frase de entrada a
 * partir do índice início.
 *
 * Entrada: - a string frase que será analisada
 *          - a string palavra onde vai ser copiada a palavra encontrada
 *          - um inteiro que representa o índice do início da palavra na frase
 *
 * Saida: devolve -1 se a string s chegou ao fim, caso contrário,
 * devolve o índice de início da próxima palavra
 */
int proxima_palavra(char frase[], char palavra[], int inicio){
  int inicioProxima = -1;
  int terminouPalavra = 0;
  unsigned int i, j, lenght;

  i = inicio;
  j = 0;
  lenght = strlen(frase);

  /* Anda na frase e na palavra ao mesmo tempo  */
  while(terminouPalavra != 1){

    /* Se na frase for um espaço significa que acabou a palavra */    
    if(frase[i] == ' ' || i == lenght ){
      palavra[j] = '\0';
      terminouPalavra = 1;
    }
    /* Se não Coloca na palavra o valor que esta na frase */
    else{
      palavra[j] = frase[i];
      i++;
      j++;
    }
  }

  /* Inicio da palavra não é o final da frase */
  if(i != (unsigned int) inicio && i < lenght){

    /* Deixa pronto para a proxima palavra */
    i++;
    inicioProxima = i;
  }

  if(i == lenght){
    inicioProxima = -1;
  }
  
  return inicioProxima;
}


/* Objetivo: verifica se palavra de entrada é um marcador temporal.
 *
 * Entrada: - recebe a matriz de marcadores temporais marcVetor;
 *          - e a palavra a ser analisada palavra.
 *
 * Saida: Se a palavra for um marcador, devolve o índice
 * correspondente em marcVetor, senão devolve -1
 */
int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[]){
    int indiceMarcador = -1;
    unsigned int i;

    /* Percorre palavras na lista de marcadores e verifica com palavra */
    for(i = 0; i < N_MARCADORES && indiceMarcador == -1; i++){
      if(strcmp(marcVetor[i], palavra) == 0){
	indiceMarcador = i;
      }
    }
    
    return indiceMarcador;
}


int indice_palavra(char palavras[][20], char palavra[], int numPalavras){
  int indicePalavra = -1;
  int i;

  /* Para cada palavras */
  for(i = 0; i < numPalavras && indicePalavra == -1; i++){

    /* Verifica se a palavra guardada é a mesma */
    if(strcmp(palavras[i],palavra) == 0){

      /* Se for, retornar indice */
      indicePalavra = i;
    }
  }

  return indicePalavra;
}

void imprime(char frase[], 
	     int marcadorNaFrase[][N_MARCADORES], 
	     char palavras[250][20],
	     int palavrasNaFrase[50][250],
	     int ocorrencia[250],
	     int numFrases,
	     int numPalavras){
  int i, j;

  printf("====================================\n");
  printf("%s\n", frase);
  printf("------------------------------------\n");
  printf("{\n");
  for(i = 0; i < numFrases; i++){
    printf("(");
    for(j = 0; j < N_MARCADORES; j++){
      printf("%d |", marcadorNaFrase[i][j]);
    }
    printf(")\n");
  }
  printf("}\n");
  printf("------------------------------------\n");
  for(i = 0; i < numPalavras; i++){
    printf("%d (%s %d)\n", i, palavras[i], ocorrencia[i]);
  }
  printf("------------------------------------\n");
  for(i = 0; i < 50; i++){
    for(j = 0; j < 250 ; j++)
      if(palavrasNaFrase[i][j] > 0){
	printf("(%d %d %d)\n", i,  j, palavrasNaFrase[i][j]);
      }
  }
  printf("------------------------------------\n");
}

int main(){
  
  int inicio;
  char palavra[20];

  char marcVetor[N_MARCADORES][TAM_MARCADORES] = MARCADORES;
  
  int numFrases;
  char frase[250];
  int marcadorNaFrase[50][N_MARCADORES];

  int numPalavras;
  char palavras[250][20];
  int ocorrencia[250];
  int palavrasNaFrase[50][250];

  int numPalavrasBusca;
  int ocorrencias_simultaneas[250][N_MARCADORES];
  int maiorOcorrenciaSimultanea;

  int i, j, k, indice, numOcorrencias, porcentagemOcorrencia;



  /* Configuração inicial */
  numPalavras = 0;

  /* Numero de frases */
  scanf("%d\n", &numFrases);

  /* Limpar marcadores na frase */
  for(i = 0; i < numFrases; i++){
    for(j = 0; j < N_MARCADORES; j++){
      marcadorNaFrase[i][j] = 0;
    }
  }

  /* Inicializa quais palavras tem na frase  */
  for(i = 0; i < 50; i++){
    for(j = 0; j < 250; j++){
      palavrasNaFrase[i][j] = 0;
    }
  }

  /* Inicializa as ocorrencias simultaneas */
  for(i = 0; i < 250; i++){
    for(j = 0; j < N_MARCADORES; j++){
      ocorrencias_simultaneas[i][j] = 0;
    }
  }

  /* Para cada frase */
  for(i = 0; i < numFrases; i++){

    /* Inicio das palavras eh o começo da frase */
    inicio = 0;

    /* Pega frase  */
    fgets(frase, 250, stdin);

    /* Padroniza frase */
    minusculas(frase);
      
    /* Enquanto tem palavra */
    do{
      /* Achar palavras */
      inicio = proxima_palavra(frase, palavra, inicio);

      /* Verificar se palavra esta na lista de palavras */
      indice = indice_palavra(palavras, palavra, numPalavras);

      /* Se não estiver, colocar ela na lista e colocar 1 no número de
	 ocorencia*/
      if(indice == -1){

	/* Coloca palavra na lista de palavras */
	strcpy(palavras[numPalavras], palavra);
	
	/* Primeira ocorrencia da palavra */
	ocorrencia[numPalavras] = 1;

	/* Aumenta a quantidade de ocorrencia da palavra na frase */
	palavrasNaFrase[i][numPalavras]++;

	/* Aumenta contador de palavras */
	numPalavras++;

      }
		
      /* Se estiver, aumentar o número de ocorrencia dela */
      else{
	/* Aumenta a quantidade de ocorrencia total da palavra */
	ocorrencia[indice]++;

	/* Aumenta a quantidade de ocorrencia da palavra na frase */
	palavrasNaFrase[i][indice]++;
      }

      /* Verificar se palavra é um marcador temporal */
      indice = verifica_marcador(marcVetor, palavra);

      if(indice != -1){
	/* Se for, atualizar a lista de marcadores na frase */
	marcadorNaFrase[i][indice]++;
      }
    }while(inicio != -1);
  }

  /* imprime(frase, marcadorNaFrase, palavras, palavrasNaFrase, */
  /* 	  ocorrencia, numFrases, numPalavras); */

  /* Número de palavras de busca */
  scanf("%d\n", &numPalavrasBusca);
 
  /* Para cada palavra */
  for(i = 0; i < numPalavrasBusca; i++){

    /* Pega palavra  */
    scanf("%s", palavra);
    minusculas(palavra);
    
    /* Pega o número de ocorrencias dela no texto */
    indice = indice_palavra(palavras, palavra, numPalavras);

    /* Percorrer o vetor de frases */
    for(j = 0; j < numFrases; j++){
      
       /* Verifica se palavra aparece na frase */
      if(palavrasNaFrase[j][indice] != 0){
	
	/* Percorre o vetor de marcadores */
	for(k = 0; k < N_MARCADORES; k++){

	  /* Verifica se o marcador apareceu na mesma frase */
	  if(marcadorNaFrase[j][k] != 0){

	    /* Se sim aumenta a ocorrencia simultanea do marcador e da
	       palavra */
	    ocorrencias_simultaneas[indice][k]++;
	  }
	}
      }
    }

    numOcorrencias = 0;
    maiorOcorrenciaSimultanea = 0; 
    for(k = 0; k < N_MARCADORES; k++){
      if(ocorrencias_simultaneas[indice][k] > maiorOcorrenciaSimultanea){
	maiorOcorrenciaSimultanea = ocorrencias_simultaneas[indice][k];
      }
    }

    if (maiorOcorrenciaSimultanea != 0){
      for(k = 0; k < N_MARCADORES; k++){
	if(ocorrencias_simultaneas[indice][k] == maiorOcorrenciaSimultanea){
	  numOcorrencias = ocorrencias_simultaneas[indice][k];
	  porcentagemOcorrencia = (numOcorrencias * 100 / ocorrencia[indice]);
	  printf("<%s> se relaciona com ", palavra);
	  printf("<%s> em %d %% das ocorrencias.\n", 
		 marcVetor[k], porcentagemOcorrencia);	    

	  ocorrencias_simultaneas[indice][k] = 0;
	}
      }
    }else{
      printf("<%s> nao se relacionou com nenhum marcador temporal.\n", palavra);
    }
    
    /* Pega o indice da maior ocorrencia simultanea */
    /* numOcorrencias = 0; */
    /* k = -1; */
    /* for(j = 0; j < N_MARCADORES; j++){ */
    /*   if(numOcorrencias < ocorrencias_simultaneas[indice][j]){ */
    /* 	numOcorrencias = ocorrencias_simultaneas[indice][j]; */
    /* 	k = j; */
    /*   }   */
    /* } */

  }

  /* imprime(frase, marcadorNaFrase, palavras, palavrasNaFrase, */
  /* 	  ocorrencia, numFrases, numPalavras); */


  /* Escreve vetor de palavras */
  for(i = 0; i < numPalavras; i++){
    printf("%s ", palavras[i]);
  }
  printf("\n");

  /* Escreve vetor de ocorrencias */
  for(i = 0; i < numPalavras; i++){
    printf("%d ", ocorrencia[i]);
  }
  printf("\n");
  return 0;
}
