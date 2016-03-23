/** INSTRUÇÕES PARA COMPILAR E EXECUTAR AG.cpp:
 * g++ -o AG AG.cpp
 * ./AG
**/

#define tamIndividuo 10	// solução
#define tamPopulacao 100// quantidade de indivíduos
#define nGeracao 50 	// nnumero de vezes que haverá uma nova geracao
#define taxaCross 60	// porcentagem de filhos gerados (em relação a população)
#define taxaMutacao 5	// porcentagem de filhos mutantes (em relação aos filhos)
#define tour 3		// quantidade de indivíduos selecionados no torneio

#include<iostream> 	// std::cout
#include<algorithm> 	// std::shuffle
#include<cmath> 	// std::pow, std::abs

/** matriz de população 
 * linhas: população inicial + seus filhos
 * colunas: tamIndividuo + função de aptidão + função de aptidão acumulada
 **/
int populacao[tamPopulacao+(tamPopulacao*taxaCross/100)][tamIndividuo+2];

int torneio(){
	int i, sorteio, melhor = rand() % tamPopulacao;
	std::cout<<"\nSorteio 1: "<<populacao[melhor][tamIndividuo];
	for (i = 1; i < tour; i++)	{
		sorteio = rand() % tamPopulacao;
		std::cout<<"\nSorteio "<<i+1<<": "<<populacao[sorteio][tamIndividuo];
		if (populacao[melhor][tamIndividuo] < populacao[sorteio][tamIndividuo])
			melhor = sorteio;
	}
	std::cout<<"\nMELHOR: "<<populacao[melhor][tamIndividuo];
	return melhor;
}

/*
void crossover(){
	int i = 0;
	while (i < nGeracoes){
		
		i++;
		
*/


void aptidao(){
	int i = 0;
	/* calcula valor de aptidão do primeiro individuo */
	populacao[i][tamIndividuo] = (std::pow(10,5) - abs(( (populacao[i][0]+populacao[i][4])*(std::pow(10,3)) + (populacao[i][1]+populacao[i][5])*(std::pow(10,2)) + (populacao[i][2]+populacao[i][6])*10 + populacao[i][3]+populacao[i][1] ) - ( populacao[i][4]*(std::pow(10,4)) + populacao[i][5]*(std::pow(10,3)) + populacao[i][2]*(pow(10,2)) + populacao[i][1]*10 + populacao[i][7])));
	/* seta aptidao acumulada do primeiro individuo */
	populacao[i][tamIndividuo + 1] = populacao[i][tamIndividuo];
	
	/* calcula aptidão e aptidão acumulada para os demais individuos */
	for (i = 1; i < tamPopulacao; i++){
		populacao[i][tamIndividuo] = (std::pow(10,5) - abs(( (populacao[i][0]+populacao[i][4])*(std::pow(10,3)) + (populacao[i][1]+populacao[i][5])*(std::pow(10,2)) + (populacao[i][2]+populacao[i][6])*10 + populacao[i][3]+populacao[i][1] ) - ( populacao[i][4]*(std::pow(10,4)) + populacao[i][5]*(std::pow(10,3)) + populacao[i][2]*(pow(10,2)) + populacao[i][1]*10 + populacao[i][7]))); 
		populacao[i][tamIndividuo + 1] = populacao[i-1][tamIndividuo+1] + populacao[i][tamIndividuo];
	}
}

void imprimePopulacao(){
	int i, j;
	for (i = 0; i < tamPopulacao; i++){
		for (j = 0; j < tamIndividuo; j++)
		  	std::cout<<populacao[i][j];	
		std::cout<<"| "<<populacao[i][tamIndividuo]<<" | Ac.: "<<populacao[i][tamIndividuo+1]<<"\n";
	}
}

void geraPopulacao(){
	int vetor[10] = {0,1,2,3,4,5,6,7,8,9}, i = 0, j;
	std::cout<<"Gerando população\n";
	while (i < tamPopulacao){
		std::random_shuffle(vetor, vetor+10); 	// mistura os elementos de vetor
		for (j = 0; j < 10; j++)
			populacao[i][j]=vetor[j];	// coloca vetor na populacao
		i++;
	}
}

main(){
  srand((unsigned)time(NULL));  
  geraPopulacao();
	aptidao();
	imprimePopulacao();
	torneio();
}
