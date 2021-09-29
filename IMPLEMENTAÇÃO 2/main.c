#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//GABRIELA MARCULINO - RGM: 41431
/* COMANDO PARA COMPILAR:
 * gcc -o main main.cpp -lm */

double f(double x) {
    double e = 2.718281828459045235360287;
    return pow(e, x) - x - 2;
}

void metodoCordas(){

    int iteracao = 1;
    int maximo = 100;
    double iteracaoUm;
    double iteracaoDois;
    double iteracaoTres;
    double erro;
    double erroAuxiliar;


    printf("DIGITE OS INTERVALOS: \n\n");

    printf("DIGITE X1: \n");
    scanf("%lf", &iteracaoUm);

    printf("DIGITE X2: ");
    scanf("%lf", &iteracaoDois);

    printf("DIGITE O VALOR DO ERRO: ");
    scanf("%lf", &erro);


    printf("\tITERACAO \tX1 \t\tX2 \t\tX3 \t\tf(x3) \t\tERRO \n\n");

    do{
        if(iteracao != maximo){

            iteracaoTres = (iteracaoUm * f(iteracaoDois) - iteracaoDois * f(iteracaoUm)) / (f(iteracaoDois) - f(iteracaoUm));
            erroAuxiliar = fabs(iteracaoUm - iteracaoDois);

            printf("\t%d\t%.10lf\t%.10lf\t%.10lf\t%.10lf\t%.10lf\n", iteracao, iteracaoUm, iteracaoDois, iteracaoTres, f(iteracaoTres), erroAuxiliar);

            iteracaoUm = iteracaoDois;
            iteracaoDois = iteracaoTres;
            iteracao++;

        }else{

            break;
        }

    }while(fabs(f(iteracaoTres)) > erro && iteracao <= maximo);

    iteracaoTres = (iteracaoUm * f(iteracaoDois) - iteracaoDois * f(iteracaoUm)) / (f(iteracaoDois) - f(iteracaoUm));
    erroAuxiliar = fabs(iteracaoUm - iteracaoDois);

    printf("\t%d\t%.10lf\t%.10lf\t%.10lf\t%.10lf\t%.10lf\n", iteracao, iteracaoUm, iteracaoDois, iteracaoTres, f(iteracaoTres), erroAuxiliar);

    erro = fabs(iteracaoUm - iteracaoDois);

    printf("OBTEVE SE %d ITERACOES: \n", iteracao);
    printf("VALOR DO ERRO: %.10lf \n", erro);
    printf("RAIZ APROXIMADA: %.10lf \n\n", iteracaoTres);
}

void metodoNewton(){

    int n;
    int iteracao = 0;
    double p;
    double res;
    double ant = 0;

    do{
        printf("DIGITE O INDICE (n): ");
        scanf("%d", &n);

    }while(n < 1);

    do{
        printf("DIGITE O RADICANDO (p, use '.', nao ','): ");
        scanf("%lf", &p);

    }while(p < 1);

    printf("DIGITE O CHUTE INICIAL: ");
    scanf("%lf", &res);

    while (res - ant != 0){

        ant = res;
        res = (1.0/n)*(((n-1)*res)+(p/pow(res, n-1)));

        if(res - ant != 0) {

            iteracao++;
            printf("ITERACAO: %d  X%d: %.9lf \n\n", iteracao, iteracao, res);
        }

    }
    printf("RAIZ = %.9lf \nITERACAO: %d \n\n", res, iteracao);
}

void menu(){

    int escolha = 0;

    do{
        printf("FEITO POR: Gabriela Marculino \n");
        printf("RGM: 41431 \n\n");

        printf("ESCOLHA UMA DAS OPCOES ABAIXO: \n\n");
        printf("(1) - METODO DAS CORDAS \n");
        printf("(2) - METODO DE NEWTON \n");
        printf("(0) - SAIR \n\n");

        scanf("%d", &escolha);

        switch (escolha){

            case 1:
                metodoCordas();
                break;

            case 2:
                metodoNewton();
                break;

            case 0:
                //sair
                break;

            default:
                printf("OPCAO INVALIDA \n");
                break;;

        }

    }while(escolha != 0);


}
int main(){

     menu();
     return 0;

}