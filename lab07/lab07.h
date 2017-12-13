/*  Laboratório 07: Hipótese de Sapir–Whorf 
 *  Arquivo de Cabeçalho: lab07.h   
 *  Descrição:   Este arquivo contém a função para transformar uma string em letras minúsculas e o cabeçalho das funções 
 *               a serem implementadas neste laboratório. Cada função contém uma breve descrição sobre o seu objetivo, 
 *               a saída esperada e uma pequena explicação dos parâmetros de entrada.
 */


/*Define os marcadores temporais*/
#define MARCADORES {"ontem", "hoje", "amanha", "agora", "logo", "cedo", "tarde", "breve", "nunca", "sempre", "jamais"}
/*Define tamanho máximo de um marcador temporal*/
#define TAM_MARCADORES 7
/*Define o número de marcadores temporais*/
#define N_MARCADORES 11


/* Função fornecida para o laboratório. */

/*  Objetivo: função que remove caracteres especiais e transforma uma string em minúsculas.
 *
 *  Entrada:  string s que sera processada
 *  Saida:    string de entrada s, no qual os caracteres foram transformados para letras minúsculas 
 */
void minusculas(char s[]){
    int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') s[j++] = s[i]-'A'+'a';
		else if ((s[i] >= 'a' && s[i] <= 'z') || s[i] == ' ') s[j++] = s[i];
	}
	s[j] = '\0';
}



/* Funções a serem implementadas */

/* Objetivo: função que extrai a próxima palavra da frase de entrada a partir do índice início.
 *
 * Entrada: - a string frase que será analisada
 *          - a string palavra onde vai ser copiada a palavra encontrada
 *          - um inteiro que representa o índice do início da palavra na frase
 * Saida:   devolve -1 se a string s chegou ao fim, caso contrário, devolve o índice de início da próxima palavra
 */
int proxima_palavra(char frase[], char palavra[], int inicio);


/* Objetivo: verifica se palavra de entrada é um marcador temporal.
 *
 * Entrada: - recebe a matriz de marcadores temporais marcVetor;
 *          - e a palavra a ser analisada palavra.
 * Saida:   Se a palavra for um marcador, devolve o índice correspondente em marcVetor, senão devolve -1
 */
int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[]);


