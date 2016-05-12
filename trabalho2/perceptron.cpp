#include<iostream> //std::cout


int p0[6][5] = {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0},
	};
int p1[6][5]; 

int exercicio;
int taxa;
int peso;

void printPadrao(int p[6][5])
{
}


void menu(){
	std::cout<<"Executar qual exercício?\n";
	std::cin>>exercicio;
	std::cout<<"Taxa de aprendizagem: ";
	std::cin>>taxa;
	std::cout<<"Pesos iniciais: \n1- Zerados\n2- Aleatórios\nOpção: "; 
	std::cin>>peso;
}

void controle(){
	switch(exercicio){
		case 1:
			break;
		}	
	}

int main(){
	menu();
	controle();
}
