/** INSTRUÇÕES PARA COMPILAR E EXECUTAR AG.cpp:
* g++ -o AG AG.cpp
* ./AG
**/

#define tamIndividuo 10	// solução
#define tamPopulacao 100// quantidade de indivíduos
#define nExecucao 1 	// quantidade de vezes que o AG irá rodar
#define nGeracao 50		// nnumero de vezes que haverá uma nova geracao
#define taxaCross 60	// porcentagem de filhos gerados (em relação a população)
#define taxaMutacao 5	// porcentagem de filhos mutantes (em relação aos filhos)
#define tour 3			// quantidade de indivíduos selecionados no torneio


#include<iostream> 	// std::cout
#include<algorithm>	// std::shuffle
#include<cmath> 	// std::pow, std::abs

/** matriz de população 
* linhas: população inicial + seus filhos
* colunas: tamIndividuo + função de aptidão + função de aptidão acumulada
**/
int populacao[tamPopulacao+taxaCross][tamIndividuo+2];

void imprimePopulacao(int ls){
	int i, j;
	for (i = 0; i < ls; i++){
		std::cout<<"Individuo "<<i<<": ";
		for (j = 0; j < tamIndividuo; j++)
			std::cout<<populacao[i][j];	
		std::cout<<"| "<<populacao[i][tamIndividuo]<<" | Ac.: "<<populacao[i][tamIndividuo+1]<<"\n";
	}
}

int random( int ls){
	return (ls * (long int) rand()/RAND_MAX);
}

int imprimeIndividuo(int indice){
	int i;
	std::cout<<"Individuo "<<indice<<": ";
	for (i = 0; i < tamIndividuo; i++)
	  std::cout<<populacao[indice][i];
	std::cout<<"\n";
}

int torneio(){
	int i, sorteio, melhor = rand() % tamPopulacao;
	std::cout<<"Sorteio 1 individuo "<<melhor<<" = "<<populacao[melhor][tamIndividuo]<<"\n";
	for (i = 1; i < tour; i++)	{
		sorteio = rand() % tamPopulacao;
		std::cout<<"Sorteio "<<i+1<<" individuo "<<sorteio<<" = "<<populacao[sorteio][tamIndividuo]<<"\n";
		if (populacao[melhor][tamIndividuo] < populacao[sorteio][tamIndividuo])
			melhor = sorteio;
	}
	imprimeIndividuo(melhor);
	return melhor;
}
void copiaPai(int pai, int filho){
	std::cout<<"Copiando pai "<<pai<<" para filho "<<filho<<'\n';
	int i;
	for (i = 0; i < tamIndividuo; i++)
		populacao[filho][i] = populacao[pai][i];
}

int crossoverCiclico(int pai1, int pai2, int filho, int ponto){
	int i;
	populacao[filho][ponto]=populacao[pai2][ponto];
	imprimeIndividuo(filho);
	populacao[filho+1][ponto]=populacao[pai1][ponto];
	imprimeIndividuo(filho+1);
	for (i = 0; i < tamIndividuo; i++)	
		if (i != ponto && populacao[filho][ponto] == populacao[filho][i])
			crossoverCiclico(pai1,pai2,filho,i);
	return 0;
}	

void geraFilhos()
{
  std::cout<<"tamanho populacao: "<<tamPopulacao<<"\n";
  int filho, pai1, pai2, ponto, retorno;
  for (filho = tamPopulacao; filho < tamPopulacao + taxaCross; filho +=2)
  {
	std::cout<<"Crossover "<<filho-tamPopulacao<<": \n";
	std::cout<<"Pai 1: \n";
	pai1 = torneio();
	std::cout<<"Pai 2: \n";
	pai2 = torneio();
	copiaPai(pai1, filho);
	copiaPai(pai2, filho+1);
	int ponto = random(tamIndividuo);
	std::cout<<"Ponto sorteado foi: "<<ponto<<'\n';
	retorno = crossoverCiclico(pai1, pai2, filho, ponto);
	}
}

/* calcula a aptidão para a função send + more = money */
void sendMore(int li){

	populacao[li][tamIndividuo] = (std::pow(10,5) - abs((
(populacao[li][0]+populacao[li][4])*(std::pow(10,3)) +
(populacao[li][1]+populacao[li][5])*(std::pow(10,2)) +
(populacao[li][2]+populacao[li][6])*10 + populacao[li][3]+populacao[li][1] ) -
(populacao[li][4]*(std::pow(10,4)) + populacao[li][5]*(std::pow(10,3)) +
populacao[li][2]*(pow(10,2)) + populacao[li][1]*10 + populacao[li][7])));
}

void aptidao(int li, int ls){
	std::cout<<"Funcao de aptidão: \n";	
	std::cout<<"LI: "<<li<<" LS: "<<ls<<"\n";
	while (li < ls){
		/* calcula valor de aptidão do primeiro individuo */
		sendMore(li);
		std::cout<<"saiu do sendMOre()\nValor de li: "<<li<<'\n';
		/* seta aptidao acumulada do primeiro individuo */
		if (li == 0)
			populacao[li][tamIndividuo + 1] = populacao[li][tamIndividuo];
		else		
			populacao[li][tamIndividuo + 1] = populacao[li-1][tamIndividuo+1] + populacao[li][ls];
		li ++;
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

int agSendMore(){
	srand((unsigned)time(NULL));  
	geraPopulacao();
	aptidao(0, tamPopulacao);
	imprimePopulacao(tamPopulacao);
	geraFilhos();
	aptidao(tamPopulacao, tamPopulacao + 30);
	imprimePopulacao(tamPopulacao + taxaCross);	
	return 0;
}

int main(){
	int i, sucesso = 0;
	for (i = 0; i <nExecucao; i++)
		if (agSendMore())
			sucesso =+1;
	return sucesso;
}
