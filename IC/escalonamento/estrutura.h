typedef struct processo
{
	int vertice;
	int processador;
	int id;
}No;

typedef struct indv
{
	No *processos;
	int avaliacao;
}Individuo;


Individuo *indv;
