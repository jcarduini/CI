#include <iostream> //std::cin, cout, cerr
#include <fstream> //ifstream
#include <string>	//std::string
#include <vector> //std::vector
#define ALFA
#define BETA
#define Q

int N = 2; //cidades

std::string nomeArquivo;
std::string tipo;
std::vector< std::vector<float> > distancias;

void inicializa(){
	
}

void controle(){
}

void menu(){
	std::cout<<"Entre com o nome do arquivo: ";
	std::cin>>nomeArquivo;
	std::cout<<"Arquivo: "<<nomeArquivo;
}

int leArquivo(){
	std::ifstream arquivo;
	arquivo.open(nomeArquivo.c_str());
	if(!arquivo){
		std::cerr<<"Erro ao abrir o arquivo "<<nomeArquivo;
		return -1;
		}
	arquivo >> tipo;
	arquivo >> N;
	int i;
	if (tipo.compare("coordenadas") == 0){
		int i, j, d;
		float x, y;
		for(i = 0; i < N; i++){
			distancias[i][i] = 0;
			arquivo >> x;
			arquivo >> y;
			std::cout<<"x: "<<x<<" - y: "<<y<<'\n';
		//	for (j = i + 1; j < N; j++){
//				d =  
//			}
		}

//		arquivo >> distancia[i]
	}		
	return 0;
}

int main(int argc, char** argv){
	menu();
	leArquivo();
	inicializa();
	controle();

	return 0;
}
