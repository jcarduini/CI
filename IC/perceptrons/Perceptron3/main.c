#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float w1[30],w2[30],w3[30],w4[30],w5[30],w6[30];
int y1,y2,y3,y4,y5,y6;
int y[5]={-1,-1,-1,-1,-1};
int desejado[5] ={0,1,-1,-1,-1};
int d0[30],d1[30],d2[30],d3[30],d4[30],d5[30];

int letraA[30]={   0,0,1,0,0,
                   0,1,0,1,0,
                   1,0,0,0,1,
                   1,1,1,1,1,
                   1,0,0,0,1,
                   1,0,0,0,1};

int letraE[30]={   1,1,1,1,1,
                   1,0,0,0,0,
                   1,1,1,0,0,
                   1,0,0,0,0,
                   1,0,0,0,0,
                   1,1,1,1,1};

int letraT[30]={   1,1,1,1,1,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0,
                   0,0,1,0,0};

int letraH[30]={   1,0,0,0,1,
                   1,0,0,0,1,
                   1,1,1,1,1,
                   1,0,0,0,1,
                   1,0,0,0,1,
                   1,0,0,0,1};

int letraC[30]={   1,1,1,1,1,
                   1,0,0,0,0,
                   1,0,0,0,0,
                   1,0,0,0,0,
                   1,0,0,0,0,
                   1,1,1,1,1};

int letraN[30]={   1,0,0,0,1,
                   1,1,0,0,1,
                   1,0,1,0,1,
                   1,0,0,1,1,
                   1,0,0,0,1,
                   1,0,0,0,1};


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

int digito2[30]={  0,1,1,1,0,
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
        w[i] = (float)(rand())/(float)(RAND_MAX)*(float)5 - 3;

}
void imprime_x(int *x)
{
    int i,j;
    printf("\nX[] = \n%d\n",x[0]);
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
    printf("\nW[] = \n");
    for(i=0; i <= 30; i++)
    {
        if(i == 0)
        {
            printf("%.2f, ",w[i]);
            printf("\n");
        }
        else{
            printf("%.2f, ",w[i]);
            if(i%5 == 0)
                printf("\n");}
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

int ativacao_final(int Y1, int Y2,int Y3, int Y4,int Y5, int Y6)
{
    if(Y1==1 && Y2==0 && Y3==0 && Y4==0 && Y5==0 && Y6==0)
        return 0;
    if(Y1==0 && Y2==1 && Y3==0 && Y4==0 && Y5==0 && Y6==0)
        return 1;
    if(Y1==0 && Y2==0 && Y3==1 && Y4==0 && Y5==0 && Y6==0)
        return 2;
    if(Y1==0 && Y2==0 && Y3==0 && Y4==1 && Y5==0 && Y6==0)
        return 3;
    if(Y1==0 && Y2==0 && Y3==0 && Y4==0 && Y5==1 && Y6==0)
        return 4;
    if(Y1==0 && Y2==0 && Y3==0 && Y4==0 && Y5==0 && Y6==1)
        return 5;

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
    if(y[0]==0 && y[1]==1 && y[2]==2 && y[3]==3 && y[4]==4 && y[5]==5)
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

int atalho(float w[30], int d[30], int esperado, int digito, int y_num)
{
    printf("Digito %d: Y%d: ",digito,y_num);
    int y_aux;
    y_aux = processa_digito_comeco(w,d,esperado);
    if(y_aux != esperado){
        printf("  incorreto\nTreinamento: " );
        imprime_pesos(w);
        imprime_x(d);
        ajustar_pesos(w,d,y_aux);
    }
    else{printf("  correto\n");}
    imprime_pesos(w);
    return y_aux;

}

int main(int argc, char *argv[ ])
{ 
    int p2[31]={1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};
    int p3[31]={1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p4[31]={1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
    int p5[31]={1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p2_1[31]={1,0,1,1,0,1,0,1,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};
    int p2_2[31]={1,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};
    int p2_3[31]={1,0,1,1,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};
    int p2_4[31]={1,0,1,1,1,0,1,1,0,1,0,0,0,0,1,1,0,0,1,1,0,0,1,0,0,0,1,1,1,1,1};
    int p2_5[31]={1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,1,1,1,1};
    int p2_6[31]={1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1};
    int p2_7[31]={1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,1,1,1,1};
    int p2_8[31]={1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1};
    int p2_9[31]={1,0,1,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,1,1,1};
    int p2_10[31]={1,0,1,1,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1};
    int p3_1[31]={1,0,1,0,1,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_2[31]={1,0,1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_3[31]={1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_4[31]={1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_5[31]={1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_6[31]={1,0,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_7[31]={1,0,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_8[31]={1,0,1,1,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_9[31]={1,0,1,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p3_10[31]={1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p4_1[31]={1,1,0,1,1,0,1,0,1,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
    int p4_2[31]={1,1,0,0,1,0,1,0,0,0,1,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
    int p4_3[31]={1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
    int p4_4[31]={1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,1,1,0,0,0,0,1,0};
    int p4_5[31]={1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,1,0,0,1,0,0,1,0};
    int p4_6[31]={1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,11,1,0,1,0,0,1,0};
    int p4_7[31]={1,1,0,0,1,0,1,0,0,1,0,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0};
    int p4_8[31]={1,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
    int p4_9[31]={1,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
    int p4_10[31]={1,1,0,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0};
    int p5_1[31]={1,1,0,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p5_2[31]={1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p5_3[31]={1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p5_4[31]={1,0,1,1,1,1,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p5_5[31]={1,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1};
    int p5_6[31]={1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1};
    int p5_7[31]={1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,1,0,0,0,1,0,1,1,1,1};
    int p5_8[31]={1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,1,0,1,1,1,1};
    int p5_9[31]={1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,0,1,1,1};
    int p5_10[31]={1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,1,0,0,1,1,1,1};
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

    int op_peso;
    int percorre =2;
    int esperado;
    int achou = 0;
    int epoca =0;
    esperado = 0;
    int opcao;

    srand(3);
    while(1)
    {


        printf("\n\nQual opcao do exercicio 1 deseja executar ?\n");
        printf("0: Treinamento padroes 0 e 1 \n");        
        printf("1: Investigar a saida da rede quando padroes distorcidos de 0 a 5 \n");
        printf("2: Investigar usando os padroes A, E, H, C, F, I \n");
        printf("3: Exit\nOpcao: ");
        scanf("%d", &opcao);
        achou =0 ;
        epoca=0;
        switch(opcao){
            case 0:

                    inicializa_x(d0,0);
                    inicializa_x(d1,1);
                    inicializa_x(d2,2);
                    inicializa_x(d3,3);
                    inicializa_x(d4,4);
                    inicializa_x(d5,5);
                    printf("0 - Zerados\n1 - Aleatorios\n");
                    scanf("%d",&op_peso);
                
                   if(!op_peso){
                        inicializa_com_zero(w1);
                        inicializa_com_zero(w2);
                        inicializa_com_zero(w3);
                        inicializa_com_zero(w4);
                        inicializa_com_zero(w5);
                        inicializa_com_zero(w6);
                    }
                    else{
                        inicializa_randomicamente(w1);
                        inicializa_randomicamente(w2);
                        inicializa_randomicamente(w3);
                        inicializa_randomicamente(w4);
                        inicializa_randomicamente(w5);
                        inicializa_randomicamente(w6);
                        
                    }                    
                    
                    imprime_x(d0);
                    imprime_x(d1);
                    imprime_x(d2);
                    imprime_x(d3);
                    imprime_x(d4);
                    imprime_x(d5);

                    printf("W inicial: \n");
                    imprime_pesos(w1);
                    imprime_pesos(w2);
                    imprime_pesos(w3);
                    imprime_pesos(w4);
                    imprime_pesos(w5);
                    imprime_pesos(w6);
                    printf("\n*************************\n\n");

                    while(achou == 0)
                    {
                        /*
                            atalho(a,b,c,d)
                            a: vetor de pesos
                            b: vetor do digito
                            c: esperado
                            d: apenas o numero para ser mostrado
                        */
                        y1 = atalho(w1,d0,1,0,1);
                        y2 = atalho(w2,d0,0,0,2);
                        y3 = atalho(w3,d0,0,0,3);
                        y4 = atalho(w4,d0,0,0,4);
                        y5 = atalho(w5,d0,0,0,5);
                        y6 = atalho(w6,d0,0,0,6);
                        y[0] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        y1 = atalho(w1,d1,0,1,1);
                        y2 = atalho(w2,d1,1,1,2);
                        y3 = atalho(w3,d1,0,1,3);
                        y4 = atalho(w4,d1,0,1,4);
                        y5 = atalho(w5,d1,0,1,5);
                        y6 = atalho(w6,d1,0,1,6);
                        y[1] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d2,0,2,1);
                        y2 = atalho(w2,d2,0,2,2);
                        y3 = atalho(w3,d2,1,2,3);
                        y4 = atalho(w4,d2,0,2,4);
                        y5 = atalho(w5,d2,0,2,5);
                        y6 = atalho(w6,d2,0,2,6);
                        y[2] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        y1 = atalho(w1,d3,0,3,1);
                        y2 = atalho(w2,d3,0,3,2);
                        y3 = atalho(w3,d3,0,3,3);
                        y4 = atalho(w4,d3,1,3,4);
                        y5 = atalho(w5,d3,0,3,5);
                        y6 = atalho(w6,d3,0,3,6);
                        y[3] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d4,0,4,1);
                        y2 = atalho(w2,d4,0,4,2);
                        y3 = atalho(w3,d4,0,4,3);
                        y4 = atalho(w4,d4,0,4,4);
                        y5 = atalho(w5,d4,1,4,5);
                        y6 = atalho(w6,d4,0,4,6);
                        y[4] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d5,0,5,1);
                        y2 = atalho(w2,d5,0,5,2);
                        y3 = atalho(w3,d5,0,5,3);
                        y4 = atalho(w4,d5,0,5,4);
                        y5 = atalho(w5,d5,0,5,5);
                        y6 = atalho(w6,d5,1,5,6);
                        y[5] = ativacao_final(y1,y2,y3,y4,y5,y6);

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
                    printf("W3->\n");
                    imprime_pesos(w3);
                    printf("\nW4->\n");
                    imprime_pesos(w4);
                    printf("W5->\n");
                    imprime_pesos(w5);
                    printf("\nW6->\n");
                    imprime_pesos(w6);
                break;
            case 1:                   

                inicializa_x(d0,0);
                inicializa_x(d1,1);
                inicializa_x(d2,2);
                inicializa_x(d3,3);
                inicializa_x(d4,4);
                inicializa_x(d5,5);
                
                printf("0 - Zerados\n1 - Aleatorios\n");
                    scanf("%d",&op_peso);
                
                   if(!op_peso){
                        inicializa_com_zero(w1);
                        inicializa_com_zero(w2);
                        inicializa_com_zero(w3);
                        inicializa_com_zero(w4);
                        inicializa_com_zero(w5);
                        inicializa_com_zero(w6);
                    }
                    else{
                        inicializa_randomicamente(w1);
                        inicializa_randomicamente(w2);
                        inicializa_randomicamente(w3);
                        inicializa_randomicamente(w4);
                        inicializa_randomicamente(w5);
                        inicializa_randomicamente(w6);
                        
                    }                    
                    

                    while(achou == 0)
                    {
                        /*
                            atalho(a,b,c,d)
                            a: vetor de pesos
                            b: vetor do digito
                            c: esperado
                            d: apenas o numero para ser mostrado
                        */
                        y1 = atalho(w1,d0,1,0,1);
                        y2 = atalho(w2,d0,0,0,2);
                        y3 = atalho(w3,d0,0,0,3);
                        y4 = atalho(w4,d0,0,0,4);
                        y5 = atalho(w5,d0,0,0,5);
                        y6 = atalho(w6,d0,0,0,6);
                        y[0] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        y1 = atalho(w1,d1,0,1,1);
                        y2 = atalho(w2,d1,1,1,2);
                        y3 = atalho(w3,d1,0,1,3);
                        y4 = atalho(w4,d1,0,1,4);
                        y5 = atalho(w5,d1,0,1,5);
                        y6 = atalho(w6,d1,0,1,6);
                        y[1] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d2,0,2,1);
                        y2 = atalho(w2,d2,0,2,2);
                        y3 = atalho(w3,d2,1,2,3);
                        y4 = atalho(w4,d2,0,2,4);
                        y5 = atalho(w5,d2,0,2,5);
                        y6 = atalho(w6,d2,0,2,6);
                        y[2] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        y1 = atalho(w1,d3,0,3,1);
                        y2 = atalho(w2,d3,0,3,2);
                        y3 = atalho(w3,d3,0,3,3);
                        y4 = atalho(w4,d3,1,3,4);
                        y5 = atalho(w5,d3,0,3,5);
                        y6 = atalho(w6,d3,0,3,6);
                        y[3] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d4,0,4,1);
                        y2 = atalho(w2,d4,0,4,2);
                        y3 = atalho(w3,d4,0,4,3);
                        y4 = atalho(w4,d4,0,4,4);
                        y5 = atalho(w5,d4,1,4,5);
                        y6 = atalho(w6,d4,0,4,6);
                        y[4] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d5,0,5,1);
                        y2 = atalho(w2,d5,0,5,2);
                        y3 = atalho(w3,d5,0,5,3);
                        y4 = atalho(w4,d5,0,5,4);
                        y5 = atalho(w5,d5,0,5,5);
                        y6 = atalho(w6,d5,1,5,6);
                        y[5] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        printf("\n");
                        if(verifica_y(y) == 1)
                            achou = 1;
                        epoca++;
                        printf("************************************************************\n\n");

                    }

                printf("\n\tInvestigando destorcoes\n\n");


                y1 = processa_digito_comeco(w1,p5_2,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,p5_2,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p5_2,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p5_2,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p5_2,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p5_2,0);
                printf("\n\n");
                y[0] = ativacao_final(y1,y2,y3,y4,y5,y6);

                y1 = processa_digito_comeco(w1,p5_3,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,p5_3,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p5_3,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p5_3,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p5_3,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p5_3,0);
                printf("\n\n");
                y[1] = ativacao_final(y1,y2,y3,y4,y5,y6);

                y1 = processa_digito_comeco(w1,p5_4,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,p5_4,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p5_4,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p5_4,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p5_4,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p5_4,0);
                printf("\n\n");
                y[2] = ativacao_final(y1,y2,y3,y4,y5,y6);

                y1 = processa_digito_comeco(w1,p5_5,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,p5_5,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p5_5,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p5_5,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p5_5,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p5_5,0);
                printf("\n\n");
                y[3] = ativacao_final(y1,y2,y3,y4,y5,y6);

                y1 = processa_digito_comeco(w1,p5_6,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,p5_6,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p5_6,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p5_6,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p5_6,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p5_6,0);
                printf("\n\n");
                y[4] = ativacao_final(y1,y2,y3,y4,y5,y6);

                y1 = processa_digito_comeco(w1,p5_7,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,p5_7,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p5_7,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p5_7,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p5_7,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p5_7,0);
                printf("\n\n");
                y[5] = ativacao_final(y1,y2,y3,y4,y5,y6);

/*
                y1 = processa_digito_comeco(w1,D2_1,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,D2_1,1);
                printf("\n");
                y3 = processa_digito_comeco(w3,D2_1,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,D2_1,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,D2_1,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,D2_1,0);
                printf("\n\n");
                y[1] = ativacao_final(y1,y2,y3,y4,y5,y6);

                y1 = processa_digito_comeco(w1,p2,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,p2,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p2,1);
                printf("\n");
                y4 = processa_digito_comeco(w4,p2,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p2,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p2,0);
                printf("\n\n");
                y[2] = ativacao_final(y1,y2,y3,y4,y5,y6);


                y1 = processa_digito_comeco(w1,p3,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,p3,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p3,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p3,1);
                printf("\n");
                y5 = processa_digito_comeco(w5,p3,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p3,0);
                printf("\n\n");
                y[3] = ativacao_final(y1,y2,y3,y4,y5,y6);


                y1 = processa_digito_comeco(w1,p4,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,p4,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p4,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p4,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p4,1);
                printf("\n");
                y6 = processa_digito_comeco(w6,p4,0);
                printf("\n\n");
                y[4] = ativacao_final(y1,y2,y3,y4,y5,y6);


                y1 = processa_digito_comeco(w1,p5,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,p5,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,p5,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,p5,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,p5,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,p5,1);
                printf("\n\n");
                y[5] = ativacao_final(y1,y2,y3,y4,y5,y6);

*/
                printf("\nDigito 0 (Saida: %d           Saida desejada: 0)", y[0]);
                printf("\nDigito 1 (Saida: %d           Saida desejada: 1)", y[1]);
                printf("\nDigito 2 (Saida: %d           Saida desejada: 2)", y[2]);
                printf("\nDigito 3 (Saida: %d           Saida desejada: 3)", y[3]);
                printf("\nDigito 4 (Saida: %d           Saida desejada: 4)", y[4]);
                printf("\nDigito 5 (Saida: %d           Saida desejada: 5)", y[5]);
                printf("\n\n\n\n\n\n");
                break;
            case 2:


                inicializa_x(d0,0);
                inicializa_x(d1,1);
                inicializa_x(d2,2);
                inicializa_x(d3,3);
                inicializa_x(d4,4);
                inicializa_x(d5,5);
                
                printf("0 - Zerados\n1 - Aleatorios\n");
                    scanf("%d",&op_peso);
                
                   if(!op_peso){
                        inicializa_com_zero(w1);
                        inicializa_com_zero(w2);
                        inicializa_com_zero(w3);
                        inicializa_com_zero(w4);
                        inicializa_com_zero(w5);
                        inicializa_com_zero(w6);
                    }
                    else{
                        inicializa_randomicamente(w1);
                        inicializa_randomicamente(w2);
                        inicializa_randomicamente(w3);
                        inicializa_randomicamente(w4);
                        inicializa_randomicamente(w5);
                        inicializa_randomicamente(w6);
                        
                    }                    
                    

                    while(achou == 0)
                    {
                        /*
                            atalho(a,b,c,d)
                            a: vetor de pesos
                            b: vetor do digito
                            c: esperado
                            d: apenas o numero para ser mostrado
                        */
                        y1 = atalho(w1,d0,1,0,1);
                        y2 = atalho(w2,d0,0,0,2);
                        y3 = atalho(w3,d0,0,0,3);
                        y4 = atalho(w4,d0,0,0,4);
                        y5 = atalho(w5,d0,0,0,5);
                        y6 = atalho(w6,d0,0,0,6);
                        y[0] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        y1 = atalho(w1,d1,0,1,1);
                        y2 = atalho(w2,d1,1,1,2);
                        y3 = atalho(w3,d1,0,1,3);
                        y4 = atalho(w4,d1,0,1,4);
                        y5 = atalho(w5,d1,0,1,5);
                        y6 = atalho(w6,d1,0,1,6);
                        y[1] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d2,0,2,1);
                        y2 = atalho(w2,d2,0,2,2);
                        y3 = atalho(w3,d2,1,2,3);
                        y4 = atalho(w4,d2,0,2,4);
                        y5 = atalho(w5,d2,0,2,5);
                        y6 = atalho(w6,d2,0,2,6);
                        y[2] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        y1 = atalho(w1,d3,0,3,1);
                        y2 = atalho(w2,d3,0,3,2);
                        y3 = atalho(w3,d3,0,3,3);
                        y4 = atalho(w4,d3,1,3,4);
                        y5 = atalho(w5,d3,0,3,5);
                        y6 = atalho(w6,d3,0,3,6);
                        y[3] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d4,0,4,1);
                        y2 = atalho(w2,d4,0,4,2);
                        y3 = atalho(w3,d4,0,4,3);
                        y4 = atalho(w4,d4,0,4,4);
                        y5 = atalho(w5,d4,1,4,5);
                        y6 = atalho(w6,d4,0,4,6);
                        y[4] = ativacao_final(y1,y2,y3,y4,y5,y6);


                        y1 = atalho(w1,d5,0,5,1);
                        y2 = atalho(w2,d5,0,5,2);
                        y3 = atalho(w3,d5,0,5,3);
                        y4 = atalho(w4,d5,0,5,4);
                        y5 = atalho(w5,d5,0,5,5);
                        y6 = atalho(w6,d5,1,5,6);
                        y[5] = ativacao_final(y1,y2,y3,y4,y5,y6);

                        printf("\n");
                        if(verifica_y(y) == 1)
                            achou = 1;
                        epoca++;
                        printf("************************************************************\n\n");

                    }
                

                printf("\n\tInvestigando destorcoes\n\n");



                y1 = processa_digito_comeco(w1,letraA,1);
                printf("\n");
                y2 = processa_digito_comeco(w2,letraA,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,letraA,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,letraA,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,letraA,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,letraA,0);
                printf("\n\n");
                y[0] = ativacao_final(y1,y2,y3,y4,y5,y6);            


                y1 = processa_digito_comeco(w1,letraE,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,letraE,1);
                printf("\n");
                y3 = processa_digito_comeco(w3,letraE,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,letraE,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,letraE,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,letraE,0);
                printf("\n\n");
                y[1] = ativacao_final(y1,y2,y3,y4,y5,y6);

                y1 = processa_digito_comeco(w1,letraN,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,letraN,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,letraN,1);
                printf("\n");
                y4 = processa_digito_comeco(w4,letraN,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,letraN,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,letraN,0);
                printf("\n\n");
                y[2] = ativacao_final(y1,y2,y3,y4,y5,y6);


                y1 = processa_digito_comeco(w1,letraT,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,letraT,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,letraT,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,letraT,1);
                printf("\n");
                y5 = processa_digito_comeco(w5,letraT,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,letraT,0);
                printf("\n\n");
                y[3] = ativacao_final(y1,y2,y3,y4,y5,y6);


                y1 = processa_digito_comeco(w1,letraH,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,letraH,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,letraH,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,letraH,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,letraH,1);
                printf("\n");
                y6 = processa_digito_comeco(w6,letraH,0);
                printf("\n\n");
                y[4] = ativacao_final(y1,y2,y3,y4,y5,y6);


                y1 = processa_digito_comeco(w1,letraC,0);
                printf("\n");
                y2 = processa_digito_comeco(w2,letraC,0);
                printf("\n");
                y3 = processa_digito_comeco(w3,letraC,0);
                printf("\n");
                y4 = processa_digito_comeco(w4,letraC,0);
                printf("\n");
                y5 = processa_digito_comeco(w5,letraC,0);
                printf("\n");
                y6 = processa_digito_comeco(w6,letraC,1);
                printf("\n\n");
                y[5] = ativacao_final(y1,y2,y3,y4,y5,y6);


                printf("\nLetra A (Saida: %d           Saida desejada: 0)", y[0]);
                printf("\nLetra E (Saida: %d           Saida desejada: 1)", y[1]);
                printf("\nLetra T (Saida: %d           Saida desejada: 2)", y[2]);
                printf("\nLetra H (Saida: %d           Saida desejada: 3)", y[3]);
                printf("\nLetra C (Saida: %d           Saida desejada: 4)", y[4]);
                printf("\nLetra N (Saida: %d           Saida desejada: 5)", y[5]);
                break;

            case 3:
                return;
        }

    }

    return 0;
}
