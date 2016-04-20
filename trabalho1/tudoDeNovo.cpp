/** INSTRUÇÕES PARA COMPILAR E EXECUTAR AG.cpp:
 * g++ -o exec arquivo.cpp
 * ./exec
 **/

#define tamIndividuo 10 // solução
#define tamPopulacao 100// quantidade de indivíduos
#define nExecucao 1000  // quantidade de vezes que o AG irá rodar
#define nGeracao 50     // numero de vezes que haverá uma nova geracao
#define taxaCross 60    // porcentagem de filhos gerados (em relação a população)
#define taxaMutacao 6   // porcentagem de filhos mutantes (em relação aos filhos)

#include<iostream> 	// std::cout
#include<ctime> 	// std::time_t 
#include<cstdlib>	// srand
#include<vector> 	// std::vector
#include<array> 	// std::array
#include<algorithm> 


struct Individuo{
	std::vector<int> gene;
	int apt;
	int aptAc;
 	std::vector<int> min;
	std::vector<int> sub;
	std::vector<int> dif;
};

std::array<Individuo, tamPopulacao+taxaCross> pop;

void printIndiv(int i){
//	std::cout<<pop(i).gente;
}

void geraPop(){
	std::vector<int> vet  = {0,1,2,3,4,5,6,7,8,9};
	/* mistura os individuos do vetor */ 
	std::random_shuffle(std::vector<int> vet);
}

int ag(){
	srand((unsigned)time(0));
	geraPop();	
}


int main(){
	int i, sucesso = 0;
	std::time_t inicio = std::time(0);
	for (i = 0; i < nExecucao; i++){
		if (ag())
			sucesso += 1;
//	 	imprimeIndividuo(0);
	}
	std::time_t fim = std::time(0);
	std::cout<<"Convergência = "<<sucesso*nExecucao/100<<'\n';
	std::cout<<"Tempo decorrido = "<<difftime(fim,inicio)<<" segundos\n";
	return sucesso;
}
