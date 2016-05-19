#include<iostream> //std::cout
#include<vector>

int distorcidos[20][6][5]= {{
	{0,1,1,1,0},
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
		{0,1,1,1,0}},	{
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0}}, {
				{0,1,1,1,0},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{0,1,1,1,0}}, {
					{0,1,1,1,0},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{0,1,1,1,0}}, {
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0}}, {
		{0,1,1,1,0},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{0,1,1,1,0}}, { 
			{0,1,1,1,0},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{1,0,0,0,1},
			{0,1,1,1,0}}, {
				{0,1,1,1,0},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{1,0,0,0,1},
				{0,1,1,1,0}}, {
					{0,1,1,1,0},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{0,1,1,1,0}},{ 
	{0,0,1,0,0},
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
			{1,1,1,1,1}}, {
		{0,0,1,0,0},
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
	{1,1,1,1,1}}, {	
		{0,0,1,0,0},
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
	{1,1,1,1,1}}, {
		{0,0,1,0,0},
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
	{1,1,1,1,1}}, {
		{0,0,1,0,0},
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
	{1,1,1,1,1}}};


		








/* Parâmetros fixos para problema 1 */


int epocas;
int bias = 1;
int linhas = 6;
int colunas = 5;

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


/* Parâmetros escolhidos pelo usuário */

int pesos = 1; /* Pesos zerados */
int w [31]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int taxa = 1;
int exercicio = 1;
int ft[2] = {0,1};

/* Funções */

/* Imprime os pesos */
void printPesos(){
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

void menu(){

	std::cout<<"Executar qual exercício?\n";
	std::cin>>exercicio;
	std::cout<<"Taxa de aprendizagem: ";
	std::cin>>taxa;
	std::cout<<"Pesos iniciais: \n1- Zerados\n2- Aleatórios\nOpção: "; 
	std::cin>>pesos;
}

/* Funcção soma */		
int soma(int p[][5], int w[30]){

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

/* Faz ajuste dos pesos de acordo com o padrão que não bateu */
void ajuste(int p[][5], int w[], int erro){

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

/* Faz treinamento com entradas 0 e 1 */
int treinamento(int epocas){

	int erro;
	bool ajusta = false;

	do{
		erro = ft[0] - soma(padrao[0], w);
		if (erro != 0){
			ajusta = true;
			ajuste(padrao[0], w, erro);
		}
		erro = ft[1] - soma(padrao[1], w);
		if (erro != 0){
			ajusta = true;
			ajuste(padrao[1], w, erro); 
		}
		epocas++;
	}while(erro != 0 && ajusta); 

	return epocas;
}

void controle(int epocas){
/*
	switch(pesos){
		case 1:			// pesos zerados 
			break;
		}*/
	switch(exercicio){
		case 1:
			int i;
			std::cout<<"Epocas: "<<treinamento(epocas)<<'\n';
			printPesos();
			
			break;
		}	
	}

int main(){

	printPadrao(padrao[2]);
/*	printPadrao(p3);
	printPadrao(p4);
	printPadrao(p5);
*/
	int epocas = 0;
//	menu();
	controle(epocas);
}
