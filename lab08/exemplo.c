/* MC102 Algoritmos e Programação de Computadores
 *  Laboratório 08: Superis Vincio Grandia
 *  Arquivo auxiliar: exemplo.c   
 *  Descrição:   Este arquivo contem um exemplo de uso das funções fornecidas
 */

#include "lab08.h"
#include <math.h>

#define max_points      500
#define max_operations  60000
#define max_style       256

#define M_PI 3.14159265358979323846

/* Esta funcao imprime a sequencia de operacoes e poligonos */
void io_demo(){
	int    n[1];
	double p[max_operations][2];
	char   s[max_operations];
	
	int i;
	/* Lendo as operações */
	scan_svg(n,p,s);
	printf("Sequencia de operações:\n");
	for(i=0;i<n[0];++i){
		printf("%c ",s[i]);
		if(s[i]=='S'||s[i]=='T')
			printf("(%.1f , %.1f)\n",p[i][0],p[i][1]);
		else if(s[i]=='R')
			printf("(%.1f)\n",p[i][0]);
		else
			printf("\n");
	}
	/* Polígonos */
	printf("Polígonos lidos:\n");
	scan_svg(n,p,s);
	while(n[0]>=0){
		printf("[");
		for(i=0;i<n[0];++i)
			printf("(%.3f,%.3f)",p[i][0],p[i][1]);
		printf("] s:[%s]\n",s);
		scan_svg(n,p,s);
	}
	printf("\n");
}

/* Esta funcao imprime um arquivo SVG ignorando as operacoes */
void file_demo(){
	/* Variaveis para armazenar todas as operacoes */
	int    op_n[1];
	double op_p[max_operations][2];
	char   op_s[max_operations];
	/* Variaveis que armazenam um poligono */
	int    n[1];
	double p[max_points][2];
	char   s[max_style];
	
	/* Lendo as operacoes */
	scan_svg(op_n,op_p,op_s);
	/* Operacoes armazenadas em (op_n,op_p,op_s) */
	
	/* Polígonos */
	scan_svg(n,p,s);
	print_svg(n,p,s);
	while(n[0]>=0){
		scan_svg(n,p,s);
		/* Ignorando operacoes e copiando poligono original */
		print_svg(n,p,s);
	}
	close_svg();
}

int main(){
	/* Descomente as chamadas abaixo para testar as funcoes */
	/*
	io_demo();
	*/
	/**/
	file_demo();
	/**/
	return 0;
}
