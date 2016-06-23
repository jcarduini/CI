#include <iostream>	// std::cin, cout, cerr
#include <string> 	// std::string
#include <fstream> 	// std::ifstream
#include <vector>	// std::vector
#include <utility>      // std::pair, std::make_pair
#include <stdio.h> 	// fscanf
#include <stdlib.h> // srand, rand
#include <sstream> 	// std::istringstream
#include <math.h> 	// hipot
#include <ctime> 	// std::time_t



#define ALFA (double) 1.0
#define BETA (double) 1.0
#define Q	(double) 1.0
#define P	(double) 0.5
#define MAXIT 	(int) 10

std::string nomeArquivo;
std::string tipo; //coordenadas ou distancias

int N;			//cidades

std::vector< std::vector<double> > distancias;
std::vector< std::vector<bool> > acessiveis;
std::vector< std::vector<double> > feromonio;
std::vector< std::vector<double> > visibilidade;
std::vector< std::vector<int> > rotas;

void menu(){
	std::cout<<"Entre com o nome do arquivo: ";
    std::cin>>nomeArquivo;
 }

int leArquivo(){
	std::ifstream arquivo(nomeArquivo.c_str());
	if(!arquivo){
	    std::cerr<<"Erro ao abrir o arquivo "<<nomeArquivo;
		return -1;
     }
	std::string linha;
	std::getline(arquivo, linha);
	std::istringstream in(linha);
	in >> tipo >> N;
	distancias.resize( N, std::vector<double>( N, -1.0));
	if (tipo.compare("coordenadas") == 0){
	int i, j = 0;
	std::vector <double> c(2*N, 0.0);
	
	while(std::getline(arquivo, linha)){
		std::istringstream in(linha);
		in >> i >> c[j] >> c[j+1];
		j+=2;
	}
	for (i = 0; i < N; i++){
		distancias[i][i] = 0;
		for (j = i + 1; j < N; j++){
			distancias[i][j] = hypot(c[i] - c[2*j], c[i+1] - c[2*j +1]); 
			distancias[j][i] = distancias[i][j];
		}
	}
}
	else 
	//FIXME
	return 0;

	return 0;
}

/* Calcula o somatorio das probabilidades das cidades acessíveis */
double somatoria(int cidade, int formiga){
	int i;
	double soma = 0.0;
	for (i = 0; i < N; i++){
		if (acessiveis[formiga][i])
			soma += pow(feromonio[cidade][i], ALFA) * pow(visibilidade[cidade][i], BETA);
	}
	return soma;
}

long double roleta(long double max){
	return max* (double)rand() /RAND_MAX;
	}

int escolhe(int origem, int formiga){
	double somaProbabilidades = somatoria(origem, formiga);
	std::cout<<"S.prob: "<<somaProbabilidades<<'\n';
	double resultado = roleta(somaProbabilidades);
	std::cout<<"Roleta: "<<resultado<<'\n';
	int k = 0, ac = 0, cidade;
	double soma = 0;
	while (soma < resultado && k < N){
		if(acessiveis[formiga][k]){
			std::cout<<origem<<" acessivel a "<<k<<'\n';
			soma += (pow(feromonio[origem][k], ALFA)*pow(visibilidade[origem][k], BETA));
			ac = k;
//			std::cout<<"soma ac:  "<<soma<<'\n';
			}
		k++;
		}

	std::cout<<"k = "<<k<<" - ac: "<<ac<<'\n';
	return ac;		
}

void evaporaFeromonio(){}

void depositaFeromonio(){
//	feromonio[i][j] += 
}

/* Cada formiga inicia em uma cidade */
void constroiRotas(){
	int cidade;
	int i, j, anterior;
	/* Cada passo é feito N vezes */
	for (i = 0; i < N; i++){
		/* Cada formiga faz um passo */
		for (j = 1; j < N; j++){
			/* Guarda cidade escolhida */
			anterior = rotas[i][j-1];
			cidade = escolhe(anterior, i);
			acessiveis[i][cidade] = false; 
			rotas[i][j] = cidade;		
		}
	}	
}

/*  */
void inicializa(){
	int i, j;

	rotas.resize( N, std::vector<int> (N));	
	
	acessiveis.resize( N, std::vector<bool> (N, true));
	/* cada cidade só não é acessível a ela mesma */	
	for (i = 0; i < N; i++)
		acessiveis[i][i] = false;
	/* inicialmente não há feromonio em nenhuma aresta */
	feromonio.resize( N, std::vector<double> (N, 1.0));
	/* representa a atrativa da cidade j a partir de i  */
	visibilidade.resize( N, std::vector<double> (N, 0));
	for (i = 0; i < N; i++){
		j = 0;
		while(j < N){
			if(j != i)
				visibilidade[i][j] = 1/distancias[i][j];			
//			std::cout<<"v["<<i<<"]["<<j<<"] = "<<visibilidade[i][j]<<"\n";
			j++;
		}
		rotas[i][0]=i;
	}
	
}

int main(){
	srand(time(0));
	menu();
	leArquivo();
	inicializa();
	constroiRotas();
	std::cout<<"rotas: \n";
	for (int i = 0; i < N; i++)
		std::cout<<"-->"<<rotas[0][i];
	evaporaFeromonio();
	depositaFeromonio();
	return 0;
}
