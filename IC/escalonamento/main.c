#include "declaracao.h"

void validacao(No* ind);
int getProc(No *a, int v);
int max_element(int ex[]);
int ultimo_executado(int qtde, int proc[]);
int avaliacao(No *a);
void copia(No *s, No *t);
void imprime_individuo(No *a);
void mutacao(int id);
int cmp(const void *a, const void *b);
int *tour(int tam_tour, int n_cross);
void crossover_ciclico(No *pai1, No *pai2);
int proximo(No *f, int valor, int nao_pode);
void gerar_pop();

int main(int argc, char *argv[])
{
    
	int u, v, w;
	int i, j, k;
	int numero_geracao;
	int tam_tour;
	int tpop_inicial;
	int geracoes;
	int numero_cross;
	int filho;
	int testes;
	int acerto;
	int avaliacao_otima;
	int numero_mut;
	int escolha_cross;

	int *selecionados;
	double porc;
	double taxa_cross;
	double taxa_mutacao;
	double t;
	double tf;
	double t_tot;
	int iter = 10;
	int seed =3;

	if(argc != 5){

    printf("\nArgumentos invalidos:\n1 - tamanho da populacao\n");
    printf("2 - numero de geracoes \n3 - Quantidade de Tour\n");
    printf("4 - taxa mutacao (%%) (ex: 0.1)\n");
	   

		printf("\n\nEX: ./nome 100 50 2 0.3\n\n");
		return 0;
	}

    tpop = atoi(argv[1]);
    numero_geracao = atoi(argv[2]);
    tam_tour = atoi(argv[3]);
   	srand (seed);

	tpop_inicial = tpop;

	 n = 18;

	for (i = 0 ; i < n ; ++i)
	{
		for (j = 0 ; j < n ; ++j)
		{
			gauss18[i][j] = 0;
			floyd[i][j] = 10000;
			dependencias[i][j] = 0;
		}
	}


    for(i=0;i<18;i++)
        for(j=0;j<18;j++)
        {
            gauss18[i][j] = arestas_pesos[i*18 +j];
            if(gauss18[i][j] != 0)
                floyd[i][j] = arestas_pesos[i*18 +j];
        }





	// FLOYD WARSHAL
	for ( k = 0; k < n; k++ )
      for ( i = 0; i < n; i++ )
         for ( j = 0; j < n; j++ )
            floyd[i][j] = min( floyd[i][j], floyd[i][k] + floyd[k][j] );
    // FLOYD WARSHAL



	for (i = 0 ; i < n ; ++i)
	{
		for (j = 0; j < n ; ++j)
		{
			if (i == j) continue;
			if (floyd[i][j]!= 10000)
				dependencias[j][i] = 1;
		}
	}



	taxa_mutacao = atof(argv[4]);


    taxa_cross = 0.6;

    avaliacao_otima = 44;

	numero_cross = (int)(taxa_cross * tpop);
	if (numero_cross & 1) ++numero_cross;

	numero_mut = (int)(taxa_mutacao * tpop);


	acerto = 0;

	t_tot = 0.0;



	
	int piorTempo = 0;
	int txPior = 0;
	for (testes = 0; testes < iter; ++testes)
	{

		gerar_pop();

		

		for (geracoes = 0; geracoes < numero_geracao; ++geracoes)
		{

			
			selecionados = tour(tam_tour, numero_cross);
	

			for (i = 0 ; i < numero_cross; i += 2)
			{
				crossover_ciclico(indv[selecionados[i]].processos, indv[selecionados[i + 1]].processos);
			}

			free(selecionados);

		
			for (i = 0 ; i < numero_mut; ++i)
			{
		
				filho = rand() % numero_cross + tpop_inicial;
				mutacao(filho);
			}
			qsort(indv, tpop, sizeof(Individuo), cmp);

			tpop = tpop_inicial;
		}

		t_tot += tf;

		if (indv[0].avaliacao == avaliacao_otima){
			++acerto;
			//printf("Iteracao %d",testes);
			//imprime_individuo(indv[0].processos);
		}else if(indv[0].avaliacao > piorTempo){
			piorTempo = indv[0].avaliacao;
			txPior = 1;
		}else if (indv[0].avaliacao == piorTempo){
			txPior++;
		}
		for (i = 0 ; i < tpop; ++i)
			free(indv[i].processos);
		free(indv);
	}

	porc = (double)acerto / iter * 100;

	printf("\n\nAcertos: %d\nPorcentagem de acerto: %.2lf\nPior solucao : %d \n\n\n",acerto,porc,piorTempo);


	return 0;
}



void validacao(No* ind)
{
	int i, j;
	No aux;

	for (i = 0 ; i < n ; ++i)
	{
		int flag = 0;
		for (j = i + 1; j < n ; ++j)
		{
				if (dependencias[ind[i].vertice][ind[j].vertice] )
				{
					aux = ind[i];
					ind[i] = ind[j];
					ind[j] = aux;

					flag = 1;
					break;
				}
		}
		if (flag) i = -1;
	}
}

int getProc(No *a, int v)
{
	int i;

	for (i = 0 ; i < n; ++i)
		if (a[i].vertice == v) return a[i].processador;
	return -1;
}

int max_element(int ex[])
{
	int i;
	int mx = ex[0];
	for (i = 1; i < n ; ++i)
		if (mx < ex[i]) mx = ex[i];
	return mx;
}


int ultimo_executado(int qtde, int proc[])
{
	return (qtde - 1 >= 0 ? proc[qtde - 1] : 0);
}

int avaliacao(No *a)
{
	int *executados;
	int processadores[2][n];
	int cont0, cont1;
	int it1, it2;
	int i, j;
	int quantidade_execucoes;
	int proc;
	int flag;
	int tempo;
	int processador_executado;
	int vertice;

	executados = (int *) malloc(n * sizeof (int));

	for (i = 0 ; i < n ; ++i) executados[i] = 0; //setar executados para 0

	cont0 = cont1 = 0;

	for (j = 0 ; j < 2; ++j)
		for (i = 0 ; i < n ; ++i) processadores[j][i] = 0; // setar 2 processadores de 18 posicoes pra 0

    /* separar quais posicoes do individui cada processador vai processar*/
	for (i = 0 ; i < n ; ++i)
	{
		if (a[i].vertice == 0)
            proc = a[i].processador;

		if (a[i].processador)
			processadores[1][cont1++] = a[i].vertice;
		else processadores[0][cont0++] = a[i].vertice;
	}

	//printf("%d %d\n", cont0, cont1);
	quantidade_execucoes = 0;
	it1 = it2 = 0;

	while (quantidade_execucoes < n)
	{
		//printf("Olhando proc %d\n", proc);
		flag = 1;
		while (flag && quantidade_execucoes < n)
		{
			if (proc)
				vertice = processadores[proc][it1];
			else
				vertice = processadores[proc][it2];

			tempo = 0;
			//printf("Olhando vertice %d\n", vertice);

			processador_executado = proc;
		//	printf("Tentando executar %d\n", vertice);
		//	printf("Olhando vertice %d no processador %d\n", vertice, proc);

			/* Para todos os vertices conectados ao "vertice" vai calcular-se o tempo */
			for(i = 0 ; i < n ; ++i)
			{
				if (gauss18[i][vertice] != 0)
				{
					if (!executados[i])
					{
						//printf("Nao executei %d\n", i);
						flag = 0;
						break;
					}
					int proc_aux = getProc(a, i); //pega o processador de i (gauss18 ij)
					int qtde = (proc != proc_aux ? gauss18[i][vertice] : 0);
					if (tempo < executados[i] + qtde)
					{
						tempo = executados[i] + qtde;
						processador_executado = proc_aux;
					}
				}
			}
			if (!flag)
			{
				//printf("vou trocar de processador\n");
				proc ^= 1;
			}
			else
			{
				++quantidade_execucoes;

				if (proc != processador_executado)
				{
					executados[vertice] = peso_vertices[vertice] + tempo;

					if (proc == 1)
					{
						if (it1 - 1 >= 0)
						{
							if (executados[processadores[proc][it1 - 1]] > tempo)
								executados[vertice] = executados[processadores[proc][it1 - 1]] + peso_vertices[vertice];

							else executados[vertice] = peso_vertices[vertice] + tempo;
						}
						else executados[vertice] = peso_vertices[vertice] + tempo;
					}
					else
					{
						if (it2 - 1 >= 0)
						{
							if (executados[processadores[proc][it2 - 1]] > tempo)
								executados[vertice] = executados[processadores[proc][it2 - 1]] + peso_vertices[vertice];
							else executados[vertice] = peso_vertices[vertice] + tempo;
						}
						else executados[vertice] = peso_vertices[vertice] + tempo;
					}
				}
				else
				{

					if (proc == 1)
					{
						if (it1 - 1 >= 0)
							executados[vertice] = peso_vertices[vertice] + executados[processadores[proc][it1 - 1]];
						else executados[vertice] = peso_vertices[vertice] + tempo;
					}
					else
					{
						if (it2 - 1 >= 0)
							executados[vertice] = peso_vertices[vertice] + executados[processadores[proc][it2 - 1]];
						else executados[vertice] = peso_vertices[vertice] + tempo;
					}
				}

				if (proc)
				{
					++it1;
					if (it1 == cont1) proc = 0;
				}
				else
				{
					++it2;
					if (it2 == cont0) proc = 1;
				}
			}
		}

	}

	return max_element(executados);
}



void gerar_pop()
{
	int i, j;
	int vUsados[n];
	indv = (Individuo *) malloc(2 * tpop * sizeof (Individuo));

	for (i = 0 ; i < 2 * tpop; ++i)
		indv[i].processos = (No *) malloc(n * sizeof (No));

	for (i = 0 ; i < tpop; ++i)
	{
		for (j = 0 ; j < n ; ++j)
			vUsados[j] = 0;

		for (j = 0 ; j < n ; ++j)
		{
			while(1){
				indv[i].processos[j].vertice = rand() % n;
				if(vUsados[indv[i].processos[j].vertice] == 0)
					break;
			}
			indv[i].processos[j].processador = rand() % 2;
			vUsados[indv[i].processos[j].vertice] = 1;
		}
		validacao(indv[i].processos);
		indv[i].avaliacao = avaliacao(indv[i].processos);
		//indv[i].id = i;
	}
}
int proximo(No *f, int valor, int nao_pode)
{
	int i;

	for (i = 0 ; i < n ;  ++i)
	{
		if (f[i].vertice == valor && i != nao_pode)
			return i;
	}
	return -1;
}

void copia(No *s, No *t)
{
	int i;
	for (i = 0 ; i < n ; ++i)
		t[i] = s[i];
}


void crossover_ciclico(No *pai1, No *pai2)
{
	No *f1 = indv[tpop].processos;
	No *f2 = indv[tpop + 1].processos;

	copia(pai1, f1);
	copia(pai2, f2);

	int ponto = rand() % n;
	do
	{
		No valor = f2[ponto];
		f2[ponto] = f1[ponto];
		f1[ponto] = valor;
		ponto = proximo(f1, valor.vertice, ponto);
	}while (ponto != -1);


	validacao(f1);
	validacao(f2);

	indv[tpop].avaliacao = avaliacao(f1);
	indv[tpop + 1].avaliacao = avaliacao(f2);

	tpop += 2;
}
double RandomInteger (int low, int high)
{
    double k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

int *tour(int tam_tour, int n_cross)
{

	int *ret;
	int i, j;
	int sel;
	int aleatorio;

	ret = (int *) malloc(sizeof(int) * n_cross);

	for (i = 0 ; i < n_cross; ++i)
	{
		sel = rand() % tpop;
		for (j = 1; j < tam_tour; ++j)
		{
			aleatorio = rand() % tpop;

			if (indv[sel].avaliacao < indv[aleatorio].avaliacao)
				sel = aleatorio;
		}
		ret[i] = sel;
	}

	return ret;
}


int cmp(const void *a, const void *b)
{
	Individuo *a1 = (Individuo *)a;
	Individuo *b1 = (Individuo *)b;

	return a1->avaliacao > b1->avaliacao;

}

void mutacao(int id)
{
	No *aux = indv[id].processos;
	No temp;

	int ponto1 = rand() % n;
	int ponto2 = rand() % n;

	temp = aux[ponto1];
	aux[ponto1] = aux[ponto2];
	aux[ponto2] = temp;

	validacao(aux);

	indv[id].avaliacao = avaliacao(aux);

}

void imprime_individuo(No *a)
{
	int i;
	printf("\n\n\t\tIndividuo otimo\n\n\n");
	for(i=0;i<n;i++)
		printf("%d %d\n",a[i].vertice,a[i].processador);

}

