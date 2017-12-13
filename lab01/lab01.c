/* Nome: Pedro Chinen */
/* RA: 175828 */
/* Laboratorio 01: Paleocontato */

#include <stdio.h>

int main(int argc, char** argv){
  /* Criacao das variaveis da base e diacriticos. */
  int base1, base2, base3, base4;
  int base5, base6, base7, base8;

  int diacritico1, diacritico2, diacritico3, diacritico4;
  int diacritico5, diacritico6, diacritico7, diacritico8;

  int multi_diacritico;

  /* Etapa 1: Contagem topologica. */

  /* Leitura dos valores de entrada */
  scanf("%d %d %d %d", &base1, &base2, &base3, &base4);
  scanf("%d %d %d %d", &base5, &base6, &base7, &base8);

  scanf("%d %d %d %d", &diacritico1, &diacritico2, &diacritico3, &diacritico4);
  scanf("%d %d %d %d", &diacritico5, &diacritico6, &diacritico7, &diacritico8);
  
  /* Etapa 2: Transformacao diacritica. */
  /* Inicialmente Xi = Bi, portanto os valores base nao precisam ser alterados. */

  /* Condições para mudar as Xi */
  /* Todos os números devem ser somados a 3,  */
  /* se o quarto diacrítico não for 2 ou 9. */
  if ((diacritico4 != 2) && (diacritico4 != 9)){
    base1 = base1 + 3;
    base2 = base2 + 3;
    base3 = base3 + 3;
    base4 = base4 + 3;
    base5 = base5 + 3;
    base6 = base6 + 3;
    base7 = base7 + 3;
    base8 = base8 + 3;
  }
  
  /* Se o primeiro diacrítico estiver entre 11 e 42 (ambos inclusive), */
  /* some 7 no oitavo número e 8 no sétimo número. */
  if ((diacritico1 >= 11) && (diacritico1 <=42)){
    base7 = base7 + 8;
    base8 = base8 + 7;
  }

  /* Se nenhum diacrítico for par,  */
  /* some o dobro do quinto diacrítico ao primeiro número. */
  if ((diacritico1 % 2 != 0) && 
      (diacritico2 % 2 != 0) &&
      (diacritico3 % 2 != 0) &&
      (diacritico4 % 2 != 0) &&
      (diacritico5 % 2 != 0) &&
      (diacritico6 % 2 != 0) &&
      (diacritico7 % 2 != 0) &&
      (diacritico8 % 2 != 0)){
    base1 = base1 + (2 * diacritico5); 
  }

  /* Se ou o terceiro ou o sexto diacríticos forem menores que 20,  */
  /* mas não ambos, some 6 no quarto e quinto números. */
  if (((diacritico3 < 20) && (diacritico6 > 20)) || 
      ((diacritico3 > 20) && (diacritico6 < 20))){
    base4 = base4 + 6;
    base5 = base5 + 6;
  }

  /* Se o último diacrítico não for 3 nem menor que o penúltimo diacrítico,  */
  /* some o segundo diacrítico ao terceiro número. */
  if ((diacritico8 != 3) && (diacritico8 >= diacritico7)){
    base3 = base3 + diacritico2;
  }

  /* Se o produto dos diacríticos for um múltiplo de 5 e não for  */
  /* um múltiplo de 10, com exceção do 30, some 1 ao sexto número. */
  multi_diacritico = diacritico1 * diacritico2 * 
    diacritico3 * diacritico4 * 
    diacritico5 * diacritico6 * 
    diacritico7 * diacritico8; 

  if (((multi_diacritico % 5 == 0) && (multi_diacritico % 10 != 0)) || 
      (multi_diacritico == 30)){
    base6 = base6 + 1;
  }

  /* Se o segundo diacrítico for igual ao último ou o terceiro for igual  */
  /* ao sétimo, também some 1 ao sexto número. */
  if ((diacritico2 == diacritico8) ||
      (diacritico3 == diacritico7)){
    base6 = base6 + 1;
  }
  
  /* Etapa 3: Conversao final */
  /* Usar esses 8 numeros para escrever a mensagem */

  /* Alterar o valor da base */
  if ((base1 > 0) && (base1 < 27)){
    base1 = base1 + 'A' - 1;
    printf("%c", base1);
  }
  if (base1 == 27){
    printf(" ");
  }

  if ((base2 > 0) && (base2 < 27)){
    base2 = base2 + 'A' - 1;
    printf("%c", base2);
  }
  if (base2 == 27){
    printf(" ");
  }

  if ((base3 > 0) && (base3 < 27)){
    base3 = base3 + 'A' - 1;
    printf("%c", base3);
  }
  if (base3 == 27){
    printf(" ");
  }

  if ((base4 > 0) && (base4 < 27)){
    base4 = base4 + 'A' - 1;
    printf("%c", base4);
  }
  if (base4 == 27){
    printf(" ");
  }

  if ((base5 > 0) && (base5 < 27)){
    base5 = base5 + 'A' - 1;
    printf("%c", base5);
  }
  if (base5 == 27){
    printf(" ");
  }

  if ((base6 > 0) && (base6 < 27)){
    base6 = base6 + 'A' - 1;
    printf("%c", base6);
  }
  if (base6 == 27){
    printf(" ");
  }

  if ((base7 > 0) && (base7 < 27)){
    base7 = base7 + 'A' - 1;
    printf("%c", base7);
  }
  if (base7 == 27){
    printf(" ");
  }

  if ((base8 > 0) && (base8 < 27)){
    base8 = base8 + 'A' - 1;
    printf("%c", base8);
  }
  if (base8 == 27){
    printf(" ");
  }

  printf("\n");

  return 0;
}
