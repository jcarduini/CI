/** INSTRUÇÕES PARA COMPILAR E EXECUTAR AG.cpp:
 * g++ -o AG AG.cpp
 * ./AG
**/

#define tamIndividuo 10	// solução
#define tamPopulacao 100	// quantidade de indivíduos
#define taxaGeracao 50	// porcentagem de filhos gerados (em relação a população)
#define taxaMutacao 5	// porcentagem de filhos mutantes (em relação aos filhos)
#define tour 3	// quantidade de indivíduos selecionados no torneio

#include<iostream> 	//std::cout
#include<algorithm> 	//std::shuffle

/** matriz de população 
 * linhas: população inicial + seus filhos
 * colunas: tamIndividuo + função de aptidão + função de aptidão acumulada
 **/
int populacao[tamPopulacao+(tamPopulacao*taxaGeracao/100)][tamIndividuo+2];


void aptidao(){
	int i;
	for (i = 0; i < tamPopulacao; i++)
		populacao[i][tamIndividuo + 1] = (populacao[i][0]+populacao[i][*10^3 + populacao[i][1]*10^2 + populacao[i][2]*10^1 + populacao[i][3]) 


void imprimePopulacao(){
	int i, j;
	for (i = 0; i < tamPopulacao; i++){
		for (j = 0; j < tamIndividuo; j++)
		  	std::cout<<populacao[i][j];	
		std::cout<<"\n";
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
	imprimePopulacao();
}
