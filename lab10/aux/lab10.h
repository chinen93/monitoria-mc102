#include<stdio.h>

typedef struct {
    unsigned short int deltaTime;
    unsigned char canal;
    unsigned char key;
    unsigned char velocity;
} TpEvento;

/* Lança na saída padrão o conteúdo de um arquivo MIDI do tipo 0 (track única)
 */
void saida(char modo, int numCanais, unsigned short int canais[], int numEventos, TpEvento *eventos){
    unsigned long int i;
    const char MThd[] = "MThd";
    /* Formato 0; track único; semínima dura 24 'durações mínimas' */
    const unsigned char headerChunk[] = {0, 0, 0, 6, 0, 0, 0, 1, 0, 24};
    const char MTrk[] = "MTrk";
    const unsigned long int comprimento = 15 + 3 * numCanais + 4 * numEventos + 4;
    /* Três colcheias por compasso, 12 'durações mínimas' por tempo, oito fusas por semínima */
    const unsigned char timeSignature[] = {0, 0xFF, 0x58, 4, 3, 3, 0x0C, 8};
    /* Andamento */
    const unsigned char tempo[] = {0, 0xFF, 0x51, 03, 5, 152, 75};
    const unsigned char endOfTrack[] = {0, 0xFF, 0x2F, 0};

    if (modo){
        /* Cabeçalho */
        for (i = 0; i < 4; i++)
            putchar(MThd[i]);
        for (i = 0; i < 10; i++)
            putchar(headerChunk[i]);
        for (i = 0; i < 4; i++)
            putchar(MTrk[i]);
        for ( i = 3; i < 4; i--)
            putchar((unsigned char)(((comprimento) >> (8 * i)) % (1 << 8)));

        for (i = 0; i < 8; i++)
            putchar(timeSignature[i]);
        for (i = 0; i < 7; i++)
            putchar(tempo[i]);

        /* Atribuição dos instrumentos */
        for (i = 0; i < numCanais; i++){
            putchar((unsigned char) 0);
            putchar((unsigned char) (192 + i));
            putchar((unsigned char) canais[i] - 1);
        }

        /* Eventos do usuário (Note On) */
        for (i = 0; i < numEventos; i++){
            putchar((unsigned char) (eventos[i]).deltaTime);
            putchar((unsigned char) (144 + (eventos[i]).canal));
            putchar((eventos[i]).key);
            putchar((eventos[i]).velocity);
        }

        /* Fim */
        for (i = 0; i < 4; i++)
            putchar(endOfTrack[i]);
    }

    else{
        printf("%d\n", numCanais);
        for (i = 0; i < numCanais; i++){
            printf("%hd", canais[i]);
            if (i + 1 != numCanais) printf(" ");
            else printf("\n");
        }
        printf("%d\n", numEventos);
        for (i = 0; i < numEventos; i++)
            printf("%hd %d %d %d\n", eventos[i].deltaTime, (int) eventos[i].canal, (int) eventos[i].key, (int) eventos[i].velocity);
    }

    return;
}
