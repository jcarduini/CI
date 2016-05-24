#include<iostream> //std::cout
#include<vector>
//#include<stdlib.h> //rand()
#include <cstdlib>
#include <ctime>
#include <cmath>

int distorcidos[20][6][5]= {{
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,1,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}},	{
		{0,0,1,1,0},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{0,1,1,1,0}},	{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,1,1,1,0}}, {
				{0,1,1,0,0},
				{1,0,0,0,1},
				{1,0,1,0,1},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{0,1,1,1,0}}, {
					{0,0,1,1,0},
					{1,1,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{0,1,1,1,0}}, {
	{0,1,1,1,0},
	{1,0,1,0,1},
	{1,0,1,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}}, {
		{0,1,1,1,0},
		{1,1,1,0,1},
		{1,0,1,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{0,1,1,1,0}}, { 
			{0,0,1,0,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,0},
			{1,0,0,0,1},
			{0,1,1,1,0}}, {
				{0,1,1,1,0},
				{1,1,0,0,1},
				{1,0,0,0,0},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{1,1,1,1,0}}, {
					{0,1,1,1,0},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{0,0,0,0,0},
					{1,0,0,0,1},
					{1,1,1,1,1}},{ 
	{0,0,0,0,0},
	{0,1,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}}, {
			{0,0,1,0,0},
			{0,1,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,1,1,1,1}}, {
		{0,0,1,0,0},
		{0,1,1,0,0},
		{0,0,1,0,1},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{1,1,1,1,1}}, {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}}, {	
		{0,0,1,0,0},
		{0,1,1,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,0,0},
		{1,1,1,1,1}}, {
	{0,1,1,1,0},
	{0,1,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}}, {
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,0,0,0},
		{0,0,1,0,0},
		{1,1,1,1,0}}, {
	{0,0,1,1,0},
	{0,1,1,0,0},
	{1,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,1,1,1,1}}, {
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,1,0,0},
		{1,1,1,1,1}}, {
	{0,1,1,1,0},
	{0,1,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,1,1,1,0}}};

int padrao[6][6][5] ={{
		{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}
	},{
	{0,0,1,0,0},
	{0,1,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}
},{
{0,1,1,1,0},
	{0,1,0,1,0},
	{0,0,0,1,0},
	{0,0,1,0,0},
	{0,1,0,0,0},
	{1,1,1,1,1}
	},{
	{0,1,1,1,1},
	{0,0,0,0,1},
	{0,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,1,1,1,1}
	},{
	{1,0,0,1,0},
	{1,0,0,1,0},
	{1,0,0,1,0},
	{1,1,1,1,0},
	{0,0,0,1,0},
	{0,0,0,1,0}
	},{
	{0,1,1,1,1},
	{0,1,0,0,0},
	{0,1,1,1,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,1,1,1,1}
	}};


/* Parâmetros fixos para problema 1 */

int padroes = 2;
int neuronios = 2;
int epocas;
int bias = 1;
int linhas = 6;
int colunas = 5;


/* Parâmetros escolhidos pelo usuário */

double w[2] [31]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
int pesos = 1; /* Pesos zerados */
//int pesos = 2; /* Pesos aleatorios */
int taxa = 1;
int exercicio = 1;
int ft[2] = {0,1};

/* Funções */

/* Imprime os pesos */
void printPesos(double w[]){
	int i;
	std::cout<<"Pesos: ";
	for (i = 0; i< 31; i++)
		std::cout<<w[i]<<' ';
	std::cout<<'\n';
}

/* Imprime um padrão */
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

/* Calcula números aleatórios de min a max */
double fRand(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	return floor( min + f * (max - min)*10)/10;
}


void menu(){

	std::cout<<"Executar qual exercício?\n";
	std::cin>>exercicio;
	std::cout<<"Taxa de aprendizagem: ";
	std::cin>>taxa;
	std::cout<<"Pesos iniciais: \n1- Zerados\n2- Aleatórios\nOpção: "; 
	std::cin>>pesos;
}

/* Função soma 
 * Exercício 1
 */		
int soma(int p[][5],double w[]){

	int i;
	int j;
	int k = 0;
	int sum = 0;
	
/* Soma ponderada com entradas xi e pesos wi */
	for (i = 0; i < linhas; i++)
		for (j = 0; j < colunas; j++){
			sum = p[i][j]*w[k];
			k++;
		}			
	
	sum += w[k]; /* Último peso =>  BIAS */

	/* Função de ativação DEGRAU */
	if (sum > 0)
		return 1;
	else 
		return 0;
}


/* Faz ajuste dos pesos de acordo com o padrão que não bateu 
 * Exercício 1
 */
void ajuste(int p[][5], int erro, double w[]){

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
	

/* Faz treinamento com entradas 0 e 1 
 * Exercício 1
 */
int treinamento(int epocas, double w[]){

	int i, erro;
	bool ajusta;
	do{
		ajusta = false;
		for (i = 0; i < padroes; i++){
			erro = ft[i] - soma(padrao[i], w);
			if (erro != 0){	
				ajusta = true;
				ajuste(padrao[i], erro, w);
			}	
		}
		epocas++;
	}while(ajusta); 

	return epocas;
}

void controle(int epocas){

	switch(pesos){
		case 1:			// pesos zerados
			break;
		case 2: 		// pesos aleatórios de -1 a 1
			int i;
			double aleatorio;
			for (i = 0; i < 31; i++){
				aleatorio =  fRand(-1,1);
				w[0][i] = aleatorio;
			}	
			printPesos(w[0]);
			break;
		
		}
	switch(exercicio){
		case 1:
			int i;
		
			std::cout<<"Epocas: "<<treinamento(epocas, w[0])<<'\n';
			printPesos(w[0]);
			std::cout<<"Dez padrões distorcidos de '0', dez padrões distorcidos de '1'\n";
			for (i = 0; i < 20; i++){
				printPadrao(distorcidos[i]);				
				std::cout<<"Padrão distorcido "<<i<<":	"<<soma(distorcidos[i],w[0])<<'\n';
			}		
			for (i =2 ; i < 6; i++){
				printPadrao(padrao[i]);
				std::cout<<soma(padrao[i], w[0])<<"\n";
			}				
			break;

		case 2:
			
			break;
		}	
	}

int main(){

	unsigned int time_ui = static_cast<unsigned int>( time(NULL)%1000 );
	srand( time_ui );
	int epocas = 0;
//	menu();
	controle(epocas);
}
