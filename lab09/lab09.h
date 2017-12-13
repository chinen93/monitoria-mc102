 /* MC102 Algoritmos e Programação de Computadores
  * Laboratório 09: A entrada do meu programa é um programa?
  * Arquivo lab09.h
  *
  * Todas as funções aqui declaradas DEVEM ser implementadas
  * Você pode implementar outras funções se desejar
  *
  * As MACROS definidas são apenas sugestões.
 */


/* Define as instruções possíveis. Você pode armazená-las da seguinte forma:
 * char nome_da_sua_variavel[N_INSTRUCOES][4] = INSTRUCOES;
 */
#define INSTRUCOES {"MOV","MOC","ADD","ADC","SUB","SUC","JMP","PTN","PTC"}
/* Número de instruções definidas na linguagem MCASSEMBLY102 */
#define N_INSTRUCOES 9
/* Número máximo de instruções que um programa pode conter */
#define MAX_PROGRAMA 150
/* Número de registradores disponíveis no computador MC102 */
#define N_REGISTRADORES 12


/* Implementa instrução MOV
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void mov(int *rd, int *ro, int *pc);

/* Implementa instrução MOV
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void moc(int *rd, int n, int *pc);

/* Implementa instrução ADD
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void add(int *rd, int *ro, int *pc);

/* Implementa instrução ADC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void adc(int *rd, int n, int *pc);

/* Implementa instrução SUB
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void sub(int *rd, int *ro, int *pc);

/* Implementa instrução SUC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void suc(int *rd, int n, int *pc);

/* Implementa instrução JMP
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void jmp(int *rd, int n, int *pc);

/* Implementa instrução PTC
 * Recebe um inteiro valor e um apontador para o Program Counter
 * Não retorna nada
 */
void ptc(int valor, int *pc);

/* Implementa instrução PTN
 * Recebe um inteiro valor e um apontador para o Program Counter
 * Não retorna nada
 */
void ptn(int valor, int *pc);
