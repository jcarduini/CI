#define tamIndividuo 10
#define tamPopulacao 100
#define taxaGeracao 50
#define taxaMutacao 5
#define tour 3

#include<iostream> 	//std::cout
#include<algorithm> 	//std::shuffle


int populacao[tamPopulacao+(tamPopulacao*taxaGeracao/100)][tamIndividuo+2];

void geraPopulacao(int pop[tamPopulacao+(tamPopulacao*taxaGeracao/100)][tamIndividuo+2]){
	int vetor[10] = {0,1,2,3,4,5,6,7,8,9}, i = 0, j;
	std::cout<<"Gerando população\n";
	while (i < tamPopulacao){
		for (j = 0; j < tamIndividuo; j++){
			//gera um vetor com permutações de 0 a 9
			std::random_shuffle(vetor, vetor+10);
			for (int k = 0; k < 10; k++)
			  std::cout<<vetor[k];
			std::cout<<"\n";
		}
		i++;
	}
}

main(){
  srand((unsigned)time(NULL));  
  geraPopulacao(populacao);

}
