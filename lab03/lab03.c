/* Nome: Pedro Chinen */
/* RA: 175828 */
/* Laboratorio 03 - Joias Siderais

   Seu objetivo é encontrar o
   tempo gasto pelo caminho especial descrito por Maria.*/

/* Informações: 

   - o valor das joias em falta no universo, em
   galactônios reais, sempre forma uma progressão aritmética

   - Os demais valores de joia no cofre pertencem a uma progressão
     geométrica iniciada pelos dois menores valores.

   - Ao receber uma ordem de pagamento, sempre pague ao cliente o
   valor da ordem usando o menor número de joias possível.

   - Sempre tem a moeda de 1 Galactônio Real

   - Para cada cliente, o cofre deve receber o pedido de joias da mais
   valiosa para a menos valiosa.

   - Estão presentes todos os valores da progressão geométrica que não
     estejam em falta no universo nem ultrapassem ₲R4.000.000.000.

   - Entrada:
   O segundo menor valor de joia presente no cofre;
   O menor valor de joia em falta do universo;
   O segundo menor valor de joia em falta do universo;
   O valor da ordem de pagamento salarial, em galactônios reais.

   - A saída do seu programa deve consistir no pedido que será feito
   ao cofre, na ordem em que este deverá entregar as joias ao
   cliente. Em cada linha deve haver dois inteiros separados por um
   espaço: o primeiro é a quantidade de joias de determinado valor; o
   segundo é o valor dessas joias em galactônios reais. Observe os
   exemplos e não se esqueça de terminar a saída com quebra de linha
   (\n).
*/

#include <stdio.h>

int main(int argc, char** argv){
  
  int segValorJoiaCofre;
  int priValorJoiaFalta, segValorJoiaFalta;
  long int valorPagamento;

  int razaoCofre, razaoFalta, joiaPresenteNoCofre;

  long int maiorJoiaCofre, joiaAtual, quantidadeJoias;

  /* Ler dados de Entrada */
  scanf("%d", &segValorJoiaCofre);
  scanf("%d", &priValorJoiaFalta);
  scanf("%d", &segValorJoiaFalta);
  scanf("%ld", &valorPagamento);

  /* Calcular as razões das PAs */
  razaoCofre = segValorJoiaCofre;
  razaoFalta = segValorJoiaFalta - priValorJoiaFalta;

  maiorJoiaCofre = 1;
  /* Achar a maior Joia que pode ser utilizada */
  for(joiaAtual = 1; 
      joiaAtual < valorPagamento; 
      joiaAtual = joiaAtual * razaoCofre){
    
    if(joiaAtual > priValorJoiaFalta){
      joiaPresenteNoCofre = (joiaAtual - priValorJoiaFalta) % razaoFalta;
    }else{
      joiaPresenteNoCofre = 1;
    }

    if( joiaPresenteNoCofre != 0 ){
      maiorJoiaCofre = joiaAtual;
    }
  }

  /* Ir descendo no valor das joias verificando se podem ser
     utilizadas */
  quantidadeJoias = 0;
  joiaAtual = maiorJoiaCofre;
  while(joiaAtual > 1 && valorPagamento > 0){

    /* Ver se pode utilizar a joia */
    if (joiaAtual >= priValorJoiaFalta){
      joiaPresenteNoCofre = (joiaAtual - priValorJoiaFalta) % razaoFalta;
    }else{
      joiaPresenteNoCofre = 1;
    }

    if( joiaPresenteNoCofre != 0 && joiaAtual <= valorPagamento){
      
      /* Pegar joia */
      quantidadeJoias = quantidadeJoias + 1;
      valorPagamento = valorPagamento - joiaAtual;
      
    }else{

      /* Se essa joia ja foi pega, escrever a quantidade pega */
      if (quantidadeJoias > 0){
	/* Imprimir quantidade */
	printf("%ld %ld\n", quantidadeJoias, joiaAtual);
	quantidadeJoias = 0;
      }

      /* Pegar outra Joia */
      joiaAtual = joiaAtual / razaoCofre;
    }
  }

  /* Imprime a quantiade de 1 galactônio real */
  if(valorPagamento > 0){
    printf("%ld 1\n", valorPagamento);
  }else{
    printf("%ld %ld\n", quantidadeJoias, joiaAtual);
  }

  return 0;
}
