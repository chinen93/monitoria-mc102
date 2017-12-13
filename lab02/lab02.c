/* Nome: Pedro Chinen */
/* RA: 175828 */
/* Laboratorio 02: Explorador de Estrelas 

   Seu objetivo é encontrar o
   tempo gasto pelo caminho especial descrito por Maria.*/

#include <stdio.h>

/* Ir de Daneb até Altair 
   Origem -> Destino = Letra correspondente ao caminho
   Daneb -> Rukh = A
   Daneb -> Sadr = B
   Daneb -> Gienah = C
   Rukh -> Sadr = D
   Rukh -> Vega = E
   Sadr -> Vega = F
   Sadr -> Albireo = G
   Gienah -> Albireo = H
   Vega -> Albireo = I
   Vega -> Altair = J
   Albireo -> Altair = K
 */

int main(int argc, char** argv){
  int A, B, C, D, E, F, G, H, I, J, K;
  
  /* Deneb-Rukh-Vega-Altair */
  int caminhoAEJ = 0;

  /* Deneb-Rukh-Vega-Albireo-Altair */
  int caminhoAEIK = 0;

  /* Deneb-Rukh-Sadr-Vega-Altair */
  int caminhoADFJ = 0;

  /* Deneb-Rukh-Sadr-Vega-Albireo-Altair */
  int caminhoADFIK = 0;

  /* Denev-Rukh-Sadr-Albidreo-Altair*/
  int caminhoADGK = 0;

  /* Deneb-Sadr-Vega-Altair */
  int caminhoBFJ = 0;

  /* Deneb-Sadr-Vega-Albireo-Altair */
  int caminhoBFIK = 0;

  /* Deneb-Sadr-Albireo-Altair */
  int caminhoBGK = 0;

  /* Deneb-Gienah-Albireo-Altair */
  int caminhoCHK = 0;
  
  /* Melhor Caminho */
  int caminho;
  
  /* Ler dados de entrada */
  scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
  scanf("%d %d %d %d %d %d", &F, &G, &H, &I, &J, &K);

  /* Calcular o valor de cada caminho*/
  caminhoAEJ = A + E + J;
  caminhoAEIK = A + E + I + K;
  caminhoADFJ = A + D + F + J;
  caminhoADFIK = A + D + F + I + K;
  caminhoADGK = A + D + G + K;
  caminhoBFJ = B + F + J;
  caminhoBFIK = B + F + I + K;
  caminhoBGK = B + G + K;
  caminhoCHK = C + H + K;

  /* Supor que primeiro caminho é o mais rapido*/
  caminho = caminhoAEJ;

  /* Ver se existe um portal intergalático nos caminhos
     O caminho especial é o mais curto entre Deneb e Altair, exceto em
     um caso: se, ao sair de Deneb, 

     ***escolhendo em cada momento o caminho mais curto para a próxima estrela***, 

     o tempo total gasto for um múltiplo
     de seis. A razão disto é que, neste último caso, abre-se um portal
     intergalático entre Deneb e Altair e o percurso torna-se
     instantâneo. Diz a lenda que é Vênus quem abre o portal.*/
  if ((caminhoAEJ % 6 == 0) && (A < B) && (A < C) && (E < D)
      && (J < I)) {
    caminhoAEJ = 0;
  }
  if ((caminhoAEIK % 6 == 0) && (A < B) && (A < C) && (E < D)
      && (I < J)){
    caminhoAEIK = 0;
  }
  if ((caminhoADFJ % 6 == 0) && (A < B) && (A < C) && (D < E) 
      && (F < G) && (J < I)){
    caminhoADFJ = 0;
  }
  if ((caminhoADFIK % 6 == 0) && (A < B) && (A < C) && (D < E) 
      && (F < G) && (I < J)){
    caminhoADFIK = 0;
  }
  if ((caminhoADGK % 6 == 0) && (A < B) && (A < C) && (D < E) 
      && (G < F)){
    caminhoADGK = 0;
  }
  if ((caminhoBFJ % 6 == 0) && (B < A) && (B < C) && (F < G)
      && (J < I)){
    caminhoBFJ = 0;
  }
  if ((caminhoBFIK % 6 == 0) && (B < A) && (B < C) && (F < G)
      && (I < J)){
    caminhoBFIK = 0;
  }
  if ((caminhoBGK % 6 == 0) && (B < A) && (B < C) && (G < F)){
    caminhoBGK = 0;
  }
  if ((caminhoCHK % 6 == 0) && (C < A) && (C < B)){
    caminhoCHK = 0;
  }

  /* Ver qual o menor caminho */
  if (caminhoAEJ < caminho){
    caminho = caminhoAEJ;
  }
  if (caminhoAEIK < caminho){
    caminho = caminhoAEIK;
  }
  if (caminhoADFJ < caminho){
    caminho = caminhoADFJ;
  }
  if (caminhoADFIK < caminho){
    caminho = caminhoADFIK;
  }
  if (caminhoADGK < caminho){
    caminho = caminhoADGK;
  }
  if (caminhoBFJ < caminho){
    caminho = caminhoBFJ;
  }
  if (caminhoBFIK < caminho){
    caminho = caminhoBFIK;
  }
  if (caminhoBGK < caminho){
    caminho = caminhoBGK;
  }
  if (caminhoCHK < caminho){
    caminho = caminhoCHK;
  }
  
  /* Imprimir o melhor caminho */
  printf("%d\n", caminho);

  return 0;
}
