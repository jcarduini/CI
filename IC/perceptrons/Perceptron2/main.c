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
        w[i] = (float)(rand())/(float)(RAND_MAX)*(float)5 -3;

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

int ativacao_final(int y1, int y2)
{
    if(y1 == 1 && y2 == 0)
        return 0;
    else if (y1 == 0 && y2 == 1)
        return 1;
    else
        return -1;
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
}


int verifica_y(int *y)
{
    int i;
    if(y[0]==0 && y[1]==1)
        return 1;
    return 0;
}

int processa_digito_comeco(float w[30], int x[30], int esperado)
{
    float net;
    int y;
    net = calcula_somatoria(w,x);
    y = ativacao(net);
    printf("  (Saida: %d            Saida desejada: %d)",y, esperado);
    return y;
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
    
    float w1[30],w2[30];
    int y1;
    int y2;
    int y[5]={-1,-1,-1,-1,-1};
    int desejado[5] ={0,1,-1,-1,-1};
    int d0[30],d1[30],d2[3],d3[30],d4[30],d5[30];
    int percorre =2;
    int esperado;
    int achou = 0;
    int epoca =0;
    esperado = 0;
    int opcao;
    int aux;
    int op_peso;
    bias = 1;

    srand(2);
    while(1)
    {

        printf("\n\nQual opcao do exercicio 1 deseja executar ?\n");
        printf("0: Treinamento padroes 0 e 1 \n");        
        printf("1: Investigar a saida da rede quando padroes distorcidos de 0 e 1 \n");
        printf("2: Investigar usando os padroes 2, 3, 4 e 5\n");
        printf("3: Exit\nOpcao: ");
        scanf("%d", &opcao);
        achou =0;
        epoca = 0;
        switch(opcao){
            case 0:
                    inicializa_x(d0,0);
                    inicializa_x(d1,1);

                    printf("0 - Zerados\n1 - Aleatorios\n");
                    scanf("%d",&op_peso);
                
                   if(!op_peso){
                        inicializa_com_zero(w1);
                        inicializa_com_zero(w2);
                    }
                    else{

                        inicializa_randomicamente(w1);
                        inicializa_randomicamente(w2);
                    }
                    
                    
                    imprime_x(d0);
                    imprime_x(d1);

                    printf("W inicial: \n");
                    imprime_pesos(w1);
                    imprime_pesos(w2);
                    printf("\n*************************\n\n");

                    while(achou == 0)
                    {
                        y1 = processa_digito_comeco(w1,d0,1);
                        
                        if(y1 != 1){
                            printf("  incorreto\nTreinamento: " );
                            imprime_pesos(w1);
                            ajustar_pesos(w1,d0,y1);
                            //imprime_pesos(w1);
                        }
                        else{printf("  correto\n");}
                        imprime_pesos(w1);

                        printf("Digito 0: Y2: ");
                        y2 = processa_digito_comeco(w2,d0,0);
                        if(y2 != 0){
                            printf("  incorreto\nTreinamento: ");
                            //imprime_pesos(w2);
                            ajustar_pesos(w2,d0,y2);
                            //imprime_pesos(w2);
                        }
                        else{printf("  correto\n");}
                        y[0] = ativacao_final(y1,y2);

                        //imprime_pesos(w2);
                        // Executa perceptron para o Digito 1, e atualiza o W se necessario
                        printf("Digito 1: Y1: ");
                        y1 = processa_digito_comeco(w1,d1,0);
                        if(y1 != 0){
                            printf("  incorreto\nTreinamento: " );
                            imprime_pesos(w1);
                            ajustar_pesos(w1,d1,y1);
                            //imprime_pesos(w1);
                        }
                        else{printf("  correto\n");}
                        imprime_pesos(w1);

                        printf("Digito 1: Y2: ");
                        y2 = processa_digito_comeco(w2,d1,1);

                        if(y2 != 1){
                            printf("  incorreto\nTreinamento: ");
                            //mprime_pesos(w2);
                            ajustar_pesos(w2,d1,y2);
                            //
                        }
                        else{printf("  correto\n");}
                        y[1] = ativacao_final(y1,y2);
                        printf("\n");
                        if(verifica_y(y) == 1)
                            achou = 1;
                        epoca++;
                        printf("************************************************************\n\n");

                    }
                    printf("Entradas reconhecidas, com %d iteracoes e o W final: \n",epoca);
                    printf("W1->\n");
                    imprime_pesos(w1);
                    printf("\nW2->\n");
                    imprime_pesos(w2);
                break;
            case 1:
                inicializa_x(d0,0);
                inicializa_x(d1,1);
                printf("0 - Zerados\n1 - Aleatorios\n");
                scanf("%d",&op_peso);
            
               if(!op_peso){
                    inicializa_com_zero(w1);
                    inicializa_com_zero(w2);
                }
                else{

                    inicializa_randomicamente(w1);
                    inicializa_randomicamente(w2);
                }
                
                
                imprime_x(d0);
                imprime_x(d1);

                printf("W inicial: \n");
                imprime_pesos(w1);
                imprime_pesos(w2);
                printf("\n*************************\n\n");

                while(achou == 0)
                {
                    // Executa perceptron para o Digito 0, e atualiza o W se necessario
                  //  pr = processa_digito_comeco(w1,d0,1);
                    if(y1 != 1){
                        printf("  incorreto\nTreinamento: " );
                        imprime_pesos(w1);
                        ajustar_pesos(w1,d0,y1);
                        //imprime_pesos(w1);
                    }
                    else{printf("  correto\n");}
                    imprime_pesos(w1);

                    printf("Digito 0: Y2: ");
                    y2 = processa_digito_comeco(w2,d0,0);
                    if(y2 != 0){
                        printf("  incorreto\nTreinamento: ");
                        //imprime_pesos(w2);
                        ajustar_pesos(w2,d0,y2);
                        //imprime_pesos(w2);
                    }
                    else{printf("  correto\n");}
                    y[0] = ativacao_final(y1,y2);

                    //imprime_pesos(w2);
                    // Executa perceptron para o Digito 1, e atualiza o W se necessario
                    printf("Digito 1: Y1: ");
                    y1 = processa_digito_comeco(w1,d1,0);
                    if(y1 != 0){
                        printf("  incorreto\nTreinamento: " );
                        imprime_pesos(w1);
                        ajustar_pesos(w1,d1,y1);
                        //imprime_pesos(w1);
                    }
                    else{printf("  correto\n");}
                    imprime_pesos(w1);

                    printf("Digito 1: Y2: ");
                    y2 = processa_digito_comeco(w2,d1,1);

                    if(y2 != 1){
                        printf("  incorreto\nTreinamento: ");
                        //mprime_pesos(w2);
                        ajustar_pesos(w2,d1,y2);
                        //
                    }
                    else{printf("  correto\n");}
                    y[1] = ativacao_final(y1,y2);
                    printf("\n");
                    if(verifica_y(y) == 1)
                        achou = 1;
                    epoca++;
                    printf("************************************************************\n\n");

                }      

                printf("\n\tDesejado 0\n");
                y1 = processa_digito_comeco(w1,D1_1,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_1,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_2,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_2,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_3,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_3,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_4,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_4,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_5,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_5,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_6,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_6,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_7,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_7,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_8,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_8,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_9,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_9,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D1_10,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,D1_10,0);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                
                printf("\n\n\tDesejado 1\n");
                printf("\n\n\n");


                printf("\n\tDesejado 0\n");
                y1 = processa_digito_comeco(w1,D2_1,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_1,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_2,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_2,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_3,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_3,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_4,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_4,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_5,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_5,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_6,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_6,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_7,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_7,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_8,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_8,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_9,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_9,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
                y1 = processa_digito_comeco(w1,D2_10,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_10,1);
                printf("\n");
                y[0] = ativacao_final(y1,y2);
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0\n\n", y[0]);
               
                break;
            case 2:
                inicializa_x(d0,0);
                inicializa_x(d1,1);
                printf("0 - Zerados\n1 - Aleatorios\n");
                scanf("%d",&op_peso);
            
               if(!op_peso){
                    inicializa_com_zero(w1);
                    inicializa_com_zero(w2);
                }
                else{

                    inicializa_randomicamente(w1);
                    inicializa_randomicamente(w2);
                }
                
                
                imprime_x(d0);
                imprime_x(d1);

                printf("W inicial: \n");
                imprime_pesos(w1);
                imprime_pesos(w2);
                printf("\n*************************\n\n");

                while(achou == 0)
                {
                    // Executa perceptron para o Digito 0, e atualiza o W se necessario
                  //  pr = processa_digito_comeco(w1,d0,1);
                    if(y1 != 1){
                        printf("  incorreto\nTreinamento: " );
                        imprime_pesos(w1);
                        ajustar_pesos(w1,d0,y1);
                        //imprime_pesos(w1);
                    }
                    else{printf("  correto\n");}
                    imprime_pesos(w1);

                    printf("Digito 0: Y2: ");
                    y2 = processa_digito_comeco(w2,d0,0);
                    if(y2 != 0){
                        printf("  incorreto\nTreinamento: ");
                        //imprime_pesos(w2);
                        ajustar_pesos(w2,d0,y2);
                        //imprime_pesos(w2);
                    }
                    else{printf("  correto\n");}
                    y[0] = ativacao_final(y1,y2);

                    //imprime_pesos(w2);
                    // Executa perceptron para o Digito 1, e atualiza o W se necessario
                    printf("Digito 1: Y1: ");
                    y1 = processa_digito_comeco(w1,d1,0);
                    if(y1 != 0){
                        printf("  incorreto\nTreinamento: " );
                        imprime_pesos(w1);
                        ajustar_pesos(w1,d1,y1);
                        //imprime_pesos(w1);
                    }
                    else{printf("  correto\n");}
                    imprime_pesos(w1);

                    printf("Digito 1: Y2: ");
                    y2 = processa_digito_comeco(w2,d1,1);

                    if(y2 != 1){
                        printf("  incorreto\nTreinamento: ");
                        //mprime_pesos(w2);
                        ajustar_pesos(w2,d1,y2);
                        //
                    }
                    else{printf("  correto\n");}
                    y[1] = ativacao_final(y1,y2);
                    printf("\n");
                    if(verifica_y(y) == 1)
                        achou = 1;
                    epoca++;
                    printf("************************************************************\n\n");

                }      
                inicializa_x(d2,2);
                inicializa_x(d3,3);
                inicializa_x(d4,4);
                inicializa_x(d5,5);

                y1 = processa_digito_comeco(w1,d2,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,d2,0);
                printf("\n");
                y[2] = ativacao_final(y1,y2);

                y1 = processa_digito_comeco(w1,d3,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,d3,0);
                printf("\n");
                y[3] = ativacao_final(y1,y2);

                y1 = processa_digito_comeco(w1,d4,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,d4,0);
                printf("\n");
                y[4] = ativacao_final(y1,y2);

                y1 = processa_digito_comeco(w1,d5,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,d5,0);
                printf("\n");
                y[5] = ativacao_final(y1,y2);

                for(aux = 2; aux <= 5; aux++)
                    printf("Digido %d: (Saida: %d)\n",aux, y[aux]);

                break;
                return;
        }

    }

    return 0;
}
