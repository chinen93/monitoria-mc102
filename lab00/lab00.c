/* Nome: Pedro Chinen
   RA: 175828
   Laboratorio 00: Vamos Comecar! */

#include <stdio.h>

int main(int argc, char *argv[]){
  
  /* Declaracao de variaveis. */
  int numero1;
  int numero2;
  int resultado;

  /* Leitura dos numeros a serem somados. */
  scanf("%d %d", &numero1, &numero2);

  /* Soma dos numeros lidos. */
  resultado = numero1 + numero2;

  /* Mostrar os numeros lidos e sua soma. */
  printf("%d - %d = %d\n", numero1, numero2, resultado);
  
  /* Finalizado o programa. */
  return 0;
}
