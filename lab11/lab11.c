/*
  Pedro Hideaki Uiechi Chinen RA175828

  Laboratório 11 - Gremlins

  
  O objetivo do jogo é bem simples: inicialmente, todos os Gremlins e
  você são colocados dentro de um círculo demarcado, malignamente, por
  Cérebro; posteriormente, seguindo as regras especificadas abaixo, você
  deve fazer sucessivas escolhas de grupos de Gremlins para saírem do
  círculo, de maneira que, ao final, sobrem EXATAMENTE 42 Gremlins junto
  com você dentro do círculo.  A escolha de quantos Gremlins saem do
  círculo deve respeitar pelo menos uma das regras a seguir,
  considerando n , o número total de Gremlins dentro do círculo.

  Se  n  é par, você pode indicar n/2 Gremlins para ficar para fora do círculo.

  Se n é divísivel por 3 ou 4, então você pode multiplicar os dois
  últimos dígitos de n e indicar essa quantidade para fora do círculo.

  Se  n  é divisível por 5, então você pode excluir exatamente 42 Gremlins.

  A escolha de qual regra adotar, a cada passo, é livre. 
*/

#include <stdio.h>


int jogo(int n){
  int retorno = 1;
  int ultimo, penultimo;

  /* printf("%d\n", n); */

  /* Se for 42: termina o programa retornando 0 da função */
  if(n == 42){
    retorno = 0;
  }

  /* Como apenas é feito subtrações a cada chamada, não existe
     possibilidade de voltar a ser 42, então termina */
  if(n < 42){
    return 1;
  }

  /* Se n é par && Ainda esta procurando */
  if((n % 2 == 0) && (retorno == 1)){
    retorno = jogo(n/2);
  }
  
  /* Se n é divisivel por 3 ou 4  && Ainda esta procurando */
  if(((n % 3 == 0) || (n % 4 == 0)) && (retorno == 1)){

    /* Pega dois ultimos numeros de n */
    if(n < 10){
      penultimo = 0;
      ultimo = n;
    }else{
      ultimo = n % 10;
      penultimo = ((n - ultimo) / 10 ) % 10;
    }
    
    /* Se a multiplicacao desses dois numeros der 0, nao vai mudar
       nada no jogo então não faz essa operação */
    if((penultimo * ultimo) != 0){
      retorno = jogo(n - (penultimo * ultimo));
    }
  }

  /* Se n é divisivel por 5 && Ainda esta procurando */
  if((n % 5 == 0)  && (retorno == 1) ){
    retorno = jogo (n - 42);
  }

  return retorno;
}


int main(){
  
  int qtdGremlins;
  int resp;

  /* Ler quantidade de gremlins no circulo */
  scanf("%d", &qtdGremlins);

  /* Pegar resposta com esta quantidade */
  resp = jogo(qtdGremlins);

  /* Verifica e escreve saida */
  if(resp == 0){
    printf("Sim\n");
  }else{
    printf("Nao\n");
  }
  
  return 0;
}
