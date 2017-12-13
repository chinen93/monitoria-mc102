
typedef struct {
        unsigned short int deltaTime;
        unsigned char canal;
        unsigned char key;
        unsigned char velocity;
} TpEvento;


void saida(char modo, 
	   int numCanais, 
	   unsigned short int *canais, 
	   int numEventos, 
	   TpEvento *eventos);
