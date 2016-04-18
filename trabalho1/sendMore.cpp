/** INSTRUÇÕES PARA COMPILAR E EXECUTAR AG.cpp:
* g++ -o AG AG.cpp
* ./AG
**/

#define tamIndividuo 10	// solução
#define tamPopulacao 100	// quantidade de indivíduos
#define nExecucao 1 	// quantidade de vezes que o AG irá rodar
#define nGeracao 50	// nnumero de vezes que haverá uma nova geracao
#define taxaCross 60	// porcentagem de filhos gerados (em relação a população)
#define taxaMutacao 5	// porcentagem de filhos mutantes (em relação aos filhos)

#include<iostream> 	// std::cout
#include<algorithm>	// std::shuffle, sts::copy
#include<cmath> 	// std::pow, std::abs
#include<vector> 	// std::vector

/** matriz de população 
* linhas: população inicial + seus filhos
* colunas: tamIndividuo + função de aptidão + função de aptidão acumulada
**/


int populacao[tamPopulacao+taxaCross][tamIndividuo+2];

int random( int ls){
	return (ls * (long int) rand()/RAND_MAX);
}


int comparaIndividuos(int* novo, int lim){
  int i, j;
  for (i = 0; i < lim; i++)
     for (j = 0; j < tamIndividuo; j++)
        if (populacao[i][j] != novo[j])
          return -1; 	// diferente
     return 0;	// igual
}

void imprimePopulacao(int ls){
	int i, j;
	for (i = 0; i < ls; i++){
		std::cout<<"Individuo "<<i<<": ";
		for (j = 0; j < tamIndividuo; j++)
			std::cout<<populacao[i][j];	
		std::cout<<"| "<<populacao[i][tamIndividuo]<<" | Ac.: "<<populacao[i][tamIndividuo+1]<<"\n";
	}
}

int imprimeIndividuo(int indice){
	int i;
	std::cout<<"Individuo "<<indice<<": ";
	for (i = 0; i < tamIndividuo; i++)
	  std::cout<<populacao[indice][i];
	std::cout<<" Apt.: "<<populacao[indice][tamIndividuo];
	std::cout<<"\n";
}

void quicksort(int esq, int dir){
	int pivo = populacao[(dir + esq)/2][tamIndividuo];

	int	i = esq;
	int j = dir;
	int aux[tamIndividuo+2];	
		
	while(i <= j){
		while (populacao[i][tamIndividuo] < pivo &&  i < dir) 
			i++;
		while (populacao[j][tamIndividuo] > pivo && j > esq) 
			j--;
		if (i <= j){
			std::copy(populacao[i], populacao[i] + tamIndividuo + 2, aux);
			std::copy(populacao[j], populacao[j] + tamIndividuo + 2, populacao[i]);
			std::copy(aux, aux + tamIndividuo + 2, populacao[j]);	
			i++;
			j--;
		}	
	}
	if (j > esq)
		quicksort(esq, j);
	if (i < dir)
		quicksort(i, dir);
}
void mutacao(int ind){
	std::cout<<"MUTACAO...";
	int ponto1 = random(10);
	int ponto2 = random(10);
	int aux = populacao[ind][ponto1];
	populacao[ind][ponto1] = populacao[ind][ponto2];
	populacao[ind][ponto2] = aux;
}

int roleta(){
  int sort = random(populacao[tamPopulacao - 1][tamIndividuo]);
  int i = 0;
  while(populacao[i][tamIndividuo] <  sort)
    i++;
  return i;
}

int torneio(int tour){
	int i, sorteio, melhor = rand() % tamPopulacao;
//	std::cout<<"Sorteio 1 individuo "<<melhor<<" = "<<populacao[melhor][tamIndividuo]<<"\n";
	for (i = 1; i < tour; i++)	{
		sorteio = rand() % tamPopulacao;
//		std::cout<<"Sorteio "<<i+1<<" individuo "<<sorteio<<" = "<<populacao[sorteio][tamIndividuo]<<"\n";
		if (populacao[melhor][tamIndividuo] < populacao[sorteio][tamIndividuo])
			melhor = sorteio;
	}
//	imprimeIndividuo(melhor);
	return melhor;
}

void copiaPai(int pai, int filho){
//	std::cout<<"Copiando pai "<<pai<<" para filho "<<filho<<'\n';
	int i;
	for (i = 0; i < tamIndividuo; i++)
		populacao[filho][i] = populacao[pai][i];
}

int crossoverCiclico(int pai1, int pai2, int filho, int ponto){
 
	int i;
	populacao[filho][ponto]=populacao[pai2][ponto];
//	imprimeIndividuo(filho);
	populacao[filho+1][ponto]=populacao[pai1][ponto];
//	imprimeIndividuo(filho+1);
	for (i = 0; i < tamIndividuo; i++)
	  if (i != ponto && populacao[filho][ponto] == populacao[filho][i])
	    crossoverCiclico(pai1,pai2,filho,i);
	return 0;
}	

void geraFilhos()
{
  std::cout<<"Gera filhos\n";
  int filho, pai1, pai2, ponto;
  for (filho = tamPopulacao; filho < tamPopulacao + taxaCross; filho +=2)
  {
 /*   pai1 = roleta();
    pai2 = roleta();
   */    
pai1 = torneio(3);
pai2 = torneio(3);
    copiaPai(pai1, filho);
    copiaPai(pai2, filho+1);
    int ponto = random(tamIndividuo);
	crossoverCiclico(pai1, pai2, filho, ponto);
	if (random(100) < 10)
		mutacao(filho);
	if (random(100) < 10)
		mutacao(filho+1); 
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
	populacao[li][tamIndividuo + 1] = populacao[li][tamIndividuo];

}

void aptidao(int li, int ls){
  std::cout<<"aptidao\n";
  while (li < ls){
    /* calcula valor de aptidão do individuo */
    sendMore(li);

    /* seta aptidao acumulada dos individuos posteriores ao primeiro */
    if (li != 0)
      populacao[li][tamIndividuo + 1] += populacao[li-1][tamIndividuo+1];
    li++;
  }
}

void geraPopulacao(){
  int vetor[10] = {0,1,2,3,4,5,6,7,8,9}, i = 0, j, k;
  std::cout<<"Gerando população...\n";
  
  /* Insere o primeiro individuo */
  std::random_shuffle(vetor, vetor+10);		// mistura os elementos de vetor
  for (j = 0; j < 10; j++)
        populacao[i][j]=vetor[j];		// coloca vetor na populacao
   i++;   
  
  while (i < tamPopulacao){
    std::random_shuffle(vetor, vetor+10); 	// mistura os elementos de vetor
    if (comparaIndividuos(vetor, i) == -1){	// verifica repetições
      for (j = 0; j < 10; j++)
        populacao[i][j]=vetor[j];	// coloca vetor na populacao
      i++;
    }
  }
}

int agSendMore(){
  srand((unsigned)time(NULL));  
  geraPopulacao();
  aptidao(0, tamPopulacao);
  geraFilhos();
//  aptidao(tamPopulacao, tamPopulacao + taxaCross);
  	
  quicksort(0, tamPopulacao - 1);
  imprimePopulacao(tamPopulacao + taxaCross);	
//	quicksort(0, tamPopulacao + taxaCross - 1);
//	imprimePopulacao(tamPopulacao + taxaCross);
	return 0;
}

int main(){
	int i, sucesso = 0;
	for (i = 0; i <nExecucao; i++)
		if (agSendMore())
			sucesso +=1;
	return sucesso;
}
