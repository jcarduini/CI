#define tamIndividuo 10
#define tamPopulacao 100
#define taxaGeracao 50
#define taxaMutacao 5
#define tour 3

#include<iostream>

int populacao[tamPopulacao+(tamPopulacao*taxaGeracao/100)][tamIndividuo+2];

void geraPopulacao(int pop[tamPopulacao+(tamPopulacao*taxaGeracao/100)][tamIndividuo+2]){
	int vetor[10], i = 0, j;
	std::cout<<"Gerando população\n";
	while (i < tamPopulacao){
		for (j = 0; j < tamIndividuo; j++){
			//gera um vetor com permutações de 0 a 9
			pop[i][j] = vetor[j];
		}
		i++;
	}
}

main(){
geraPopulacao(populacao);

}
