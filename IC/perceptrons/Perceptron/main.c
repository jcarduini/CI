#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bias;

int digito0[30]={  0,1,1,1,0,
                   1,0,0,0,1,
                   1,0,0,0,1,
                   1,0,0,0,1,
                   1,0,0,0,1,
                   0,1,1,1,0};

int digito1[30]={  0,0,1,0,0,
                   0,1,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   1,1,1,1,1};

int digito2[30]={ 0,1,1,1,0,
                   0,1,0,1,0,
                   0,0,0,1,0,
                   0,0,1,0,0,
                   0,1,0,0,0,
                   1,1,1,1,1};

int digito3[30] = {0,1,1,1,1,
                   0,0,0,0,1,
                   0,1,1,1,1,
                   0,0,0,0,1,
                   0,0,0,0,1,
                   0,1,1,1,1};

int digito4[30] = {1,0,0,1,0,
                   1,0,0,1,0,
                   1,0,0,1,0,
                   1,1,1,1,0,
                   0,0,0,1,0,
                   0,0,0,1,0};

int digito5[30] = {0,1,1,1,1,
                   0,1,0,0,0,
                   0,1,1,1,1,
                   0,0,0,0,1,
                   0,0,0,0,1,
                   0,1,1,1,1};

void inicializa_x(int *x, int digito)
{
    int i;

    x[0] = 1;
    if(digito==0)
        for(i=0;i<30;i++)
            x[i+1] = digito0[i];
    else if(digito==1)
        for(i=0;i<30;i++)
            x[i+1] = digito1[i];
    else if(digito==2)
        for(i=0;i<30;i++)
            x[i+1] = digito2[i];
    else if(digito==3)
        for(i=0;i<30;i++)
            x[i+1] = digito3[i];
    else if(digito==4)
        for(i=0;i<30;i++)
            x[i+1] = digito4[i];
    else if(digito==5)
        for(i=0;i<30;i++)
            x[i+1] = digito5[i];
    else
    {
        printf("O numero do digito deve ser entre 0 e 5");
        exit(0);
    }
}
void inicializa_com_zero(float w[30])
{
    int i,j;
    for(i=0; i <= 30; i++)
            w[i] = 0.0;
}

void inicializa_randomicamente(float w[30])
{
    int i;

    for(i=0; i <= 30; i++)
        w[i] = ((float)rand()/(float)(RAND_MAX))*5 -3;

}
void imprime_x(int *x)
{
    int i,j;
    printf("\nX[] = \n");
    for(i=1; i <= 30; i++)
    {
        printf("%d ",x[i]);
        if(i%5 == 0)
            printf("\n");
    }
    printf("\n\n");
}
void imprime_pesos(float w[30])
{
    int i,j;

    printf("\nBias: %.2f", w[0]);
    printf("\nW[] = \n");
    for(i=1; i <= 30; i++)
    {
        printf("%.2f, ",w[i]);
        if(i%5 == 0)
            printf("\n");
    }
    printf("\n\n");
}

float calcula_somatoria(float w[30], int* x)
{
    int i,j;
    float net=0.0;
    float aux;
    for(i=0;i<=30;i++)
    {
        aux = w[i]*x[i];
            net += aux;
    }
    return net;
}

int ativacao(float net)
{
    if(net > 0)
        return 1;
    else
        return 0;
}

int ajustar_pesos(float w[30], int *x, int y)
{
    int i,j;
    if(y==0)
    {
        for(i=0;i<=30;i++)
            w[i] = w[i] + x[i];

    }
    if(y==1)
    {
        for(i=0;i<=30;i++)
            w[i] = w[i] - x[i];

    }
    //imprime_pesos(w);
}

void processa_digito(float w[30],int *x,int *y,int esperado)
{
    int res;
    float net;

    res =0;
    //imprime_pesos(w);
    printf("\nDigito: %d",esperado);
    net = calcula_somatoria(w,x);
    y[esperado] = ativacao(net);
    //printf("\nSoma: %f",net);
    printf("  (Saida: %d            Saida desejada: %d)",y[esperado], esperado);


}

int verifica_y(int *y, int *desejado)
{
    int i;
    for(i = 0; i< 5;i++)
        if(y[i] != desejado[i])
            return 0;
    return 1;
}

int main(int argc, char *argv[ ])
{
    int D1_1[31]={1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0};
    int D2_1[31]={1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1};
    int D1_2[31]={1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0};
    int D2_2[31]={1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1};                
    int D1_3[31]={1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,1,0,1,1,1,0};
    int D2_3[31]={1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,1,1,1,1};
    int D1_4[31]={1,0,0,0,1,0,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1,0};
    int D2_4[31]={1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1};
    int D1_5[31]={1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,0};
    int D2_5[31]={1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0};
    int D1_6[31]={1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,1,0,1,0,0,0,1,0,1,1,1,0};
    int D2_6[31]={1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,1,1,1,1};
    int D1_7[31]={1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0};
    int D2_7[31]={1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,1,0};
    int D1_8[31]={1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,1,1,0,1,1,0};
    int D2_8[31]={1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1};
    int D1_9[31]={1,0,0,0,1,0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,1,1,1,0};
    int D2_9[31]={1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1};
    int D1_10[31]={1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,0};
    int D2_10[31]={1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0};
                

    float w[30];
    int y[5]={-1,-1,-1,-1,-1};
    int desejado[5] ={0,1,-1,-1,-1};
    int d0[30],d1[30],d2[3],d3[30],d4[30],d5[30];
    int percorre =2;
    int esperado;
    int achou = 0;
    int epoca =0;
    esperado = 0;
    int opcao;
    int op_peso;

    bias = 1;


    srand(2);

    while(1)
    {

        printf("\n\nQual opcao do exercicio 1 deseja executar ?\n");
        printf("0: Treinamento padroes 0 e 1\n"); 
        printf("1: Investigar a saida da rede quando padroes distorcidos de 0 e 1 \n");
        printf("2: Investigar usando os padroes 2, 3, 4 e 5 \n5: Exit\nOpcao: ");
        scanf("%d", &opcao);    
        achou =0;
        switch(opcao){
            case 0:
                    inicializa_x(d0,0);
                    inicializa_x(d1,1);
	
                    printf("0 - Zerados\n1 - Aleatorios\n");
                    scanf("%d",&op_peso);
                
                   if(!op_peso)
                        inicializa_com_zero(w);

                    else
                        inicializa_randomicamente(w);
                       
                    imprime_x(d0);
                    imprime_x(d1);

                    printf("W inicial: \n");
                    imprime_pesos(w);
                    printf("\n*****************\n\n");
                    while(achou == 0)
                    {
                        processa_digito(w,d0,y,0);
                        if(y[0] != desejado[0]){
                            printf("  incorreto\nTreinamento: " );
                            ajustar_pesos(w,d0,y[0]);
                            imprime_pesos(w);
                        }
                        else{printf("  correto\n");}
                        processa_digito(w,d1,y  ,1);
                        if(y[1] != desejado[1]){
                            printf("  incorreto\nTreinamento: ");
                            ajustar_pesos(w,d1,y[1]);
                            imprime_pesos(w);
                        }
                        else{printf("  correto\n");}
                        printf("\n");
                        if(verifica_y(y,desejado) == 1)
                            achou = 1;
                        epoca++;
                    }
                    imprime_pesos(w);
                    printf("Entradas reconhecidas, com %d iteracoes e o W final: \n",epoca);

                break;
            case 1:
                inicializa_x(d0,0);
                inicializa_x(d1,1);
                printf("0 - Zerados\n1 - Aleatorios\n");
                scanf("%d",&op_peso);
                
                if(!op_peso)
                    inicializa_com_zero(w);
                else 
                    inicializa_randomicamente(w);

                imprime_x(d0);
                imprime_x(d1);


                printf("W inicial: \n");
                imprime_pesos(w);
                printf("\n*****************\n\n");
                while(achou == 0)
                {
                    processa_digito(w,d0,y,0);
                    if(y[0] != desejado[0]){
                        printf("  incorreto\nTreinamento: " );
                        ajustar_pesos(w,d0,y[0]);
                        imprime_pesos(w);
                    }
                    else{printf("  correto\n");}
                    processa_digito(w,d1,y  ,1);
                    if(y[1] != desejado[1]){
                        printf("  incorreto\nTreinamento: ");
                        ajustar_pesos(w,d1,y[1]);
                        imprime_pesos(w);
                    }
                    else{printf("  correto\n");}
                    printf("\n");
                    if(verifica_y(y,desejado) == 1)
                        achou = 1;
                    epoca++;
                }
                

                printf("\n\tDesejado 0\n");
                processa_digito(w,D1_1,y,0);
                processa_digito(w,D1_2,y,0);
                processa_digito(w,D1_3,y,0);
                processa_digito(w,D1_4,y,0);
                processa_digito(w,D1_5,y,0);
                processa_digito(w,D1_6,y,0);
                processa_digito(w,D1_7,y,0);
                processa_digito(w,D1_8,y,0);
                processa_digito(w,D1_9,y,0);
                processa_digito(w,D1_10,y,0);

                printf("\n\tDesejado 1\n");
                processa_digito(w,D2_1,y,1);
                processa_digito(w,D2_2,y,1);
                processa_digito(w,D2_3,y,1);
                processa_digito(w,D2_4,y,1);
                processa_digito(w,D2_5,y,1);
                processa_digito(w,D2_6,y,1);
                processa_digito(w,D2_7,y,1);
                processa_digito(w,D2_8,y,1);
                processa_digito(w,D2_9,y,1);
                processa_digito(w,D2_10,y,1);

                printf("\n\n\n");
                break;
            
            case 2:
                inicializa_x(d0,0);
                inicializa_x(d1,1);
                printf("0 - Zerados\n1 - Aleatorios\n");
                scanf("%d",&op_peso);
                
                if(!op_peso)
                    inicializa_com_zero(w);
                else 
                    inicializa_randomicamente(w);

                imprime_x(d0);
                imprime_x(d1);


                printf("W inicial: \n");
                imprime_pesos(w);
                printf("\n*****************\n\n");
                while(achou == 0)
                {
                    processa_digito(w,d0,y,0);
                    if(y[0] != desejado[0]){
                        printf("  incorreto\nTreinamento: " );
                        ajustar_pesos(w,d0,y[0]);
                        imprime_pesos(w);
                    }
                    else{printf("  correto\n");}
                    processa_digito(w,d1,y  ,1);
                    if(y[1] != desejado[1]){
                        printf("  incorreto\nTreinamento: ");
                        ajustar_pesos(w,d1,y[1]);
                        imprime_pesos(w);
                    }
                    else{printf("  correto\n");}
                    printf("\n");
                    if(verifica_y(y,desejado) == 1)
                        achou = 1;
                    epoca++;
                }
 
                inicializa_x(d2,2);
                inicializa_x(d3,3);
                inicializa_x(d4,4);
                inicializa_x(d5,5);
 
                processa_digito(w,d2,y,2);
                processa_digito(w,d3,y,3);
                processa_digito(w,d4,y,4);
                processa_digito(w,d5,y,5);
                break;
            case 5:
                return;
        }

    }

    return 0;
}
