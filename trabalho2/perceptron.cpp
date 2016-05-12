#include<iostream> //std::cout

/* Parâmetros fixos para problema 1 */


int epocas;
int bias = 1;
int linhas = 6;
int colunas = 5;

int p0[6][5] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
	};
int ft0 = 0;

int p1[6][5]; 


/* Parâmetros escolhidos pelo usuário */

int pesos = 1; /* Pesos zerados */
int w [31]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int taxa = 1;
int exercicio = 1;


/* Funções */

void menu(){
	std::cout<<"Executar qual exercício?\n";
	std::cin>>exercicio;
	std::cout<<"Taxa de aprendizagem: ";
	std::cin>>taxa;
	std::cout<<"Pesos iniciais: \n1- Zerados\n2- Aleatórios\nOpção: "; 
	std::cin>>pesos;
}

void printPadrao(int p[][5])
{
	int i;
	int j;

	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			if (p[i][j] == 0)
				std::cout<<" ";
			else
				std::cout<<"#";
		}
		std::cout<<'\n';
	}
}

int soma(int p[][5], int w[30]){
	
	int i;
	int j;
	int k = 0;
	int retorno = 0;
	
	for (i = 0; i < linhas; i++)
		for (j = 0; j < colunas; j++){
			retorno += p[i][j]*w[k];
			k++;
		}			
	soma += w[k]; 				/* Último peso do BIAS */
	std::cout<<"soma: "<<retorno;
	return retorno;
}

void ajuste(int [][5]p, int erro){

	int i;
	int j;
	int k = 0;
	
	for (i = 0; i < linhas; i++)
		for (j = 0; j < colunas; j++){
			w[k] = w[k] +  erro*taxa*p[i][j];
			k++;
		}
		w[k] = w[k] + erro*taxa*bias;
}

void exercicio1(){

	int erro;
	do{
		erro = ft0 - soma(p0, w);
		if (erro != 0)
			ajuste(p0, w, erro);
	}while(erro > 0); 
}

void controle(){
/*
	switch(pesos){
		case 1:			// pesos zerados 
			break;
		}*/
	switch(exercicio){
		case 1:
			soma(p0, w);
			break;
		}	
	}

int main(){
//	printPadrao(p0);
//	menu();
	controle();
}
