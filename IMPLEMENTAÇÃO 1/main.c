#include <stdlib.h>
#include <stdio.h>

/*
 * POR: GABRIELA MARCULINO
 * RGM: 41431
 */

int main (){
    
    int linha = 0;
    int coluna = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    printf ("Digite a ordem da matriz: \n\n");
    scanf ("%i", &linha);
    coluna = linha; //para haver apenas matrizes quadradas

    if((linha <= 1) || (linha > 10)){

        printf("So aceitamos matrizes de no maximo ordem 10\n");

    }else{

        float matriz[linha][coluna];
        float identidade[linha][coluna];
        float auxiliar = 0;
        float pivo = 0;
        float auxPivo = 0;

        for(i = 0; i < linha; i++){

            for(j = 0; j < coluna; j++){

                if(i == j){                     //se a linha for igual a coluna, substitui por 1

                    identidade[i][j] = 1;       //substituindo os elementos para obter a matriz identidade
                }
                else{
                    identidade[i][j] = 0;
                }
            }
        }


        printf ("Digite os elementos da matriz: \n\n");

        for(i = 0; i < linha; i++){                    //inserindo os elementos na matriz de ordem N

            for(j = 0; j < coluna; j++){

                printf("Digite os elementos de Aij(%i,%i):\n", i + 1, j + 1);
                scanf("%f", &matriz[i][j]);
            }
        }


        printf("MATRIZ:\n");

        for(i = 0; i < linha; i++){

            for(j = 0; j < coluna; j++){       //print da matriz

                printf ("%.2f", matriz[i][j]);

                if(j < coluna - 1){

                    printf("\t"); //dar espaco do tamanho de um paragrafo

                }else{

                    printf("\n");
                }

            }

        }


        for(j = 0; j < coluna; j++){

            pivo = matriz[j][j];
            auxPivo = pivo / pivo;

            for(k = j; k < coluna; k++){       //calculando a matriz inversa

                matriz[j][k] = (matriz[j][k]) / (pivo);
                identidade[j][k] = (identidade[j][k]) / (pivo);
            }
            for(i = 0; i < linha; i++){

                if(i != j){

                    auxiliar = matriz[i][j] / auxPivo;

                    for(k = 0; k < coluna; k++){

                        matriz[i][k] = matriz[i][k] - (auxiliar * matriz[j][k]);
                        identidade[i][k] = identidade[i][k] - (auxiliar * identidade[j][k]);
                    }
                }
            }
        }



        printf("MATRIZ IDENTIDADE: \n");
        for(i = 0; i < linha; i++)
        {
            for(j = 0; j < coluna; j++)
            {
                printf("%.2f", matriz[i][j]);  //print da matriz identidade
                if(j < coluna - 1){

                    printf ("\t");

                }else{

                    printf ("\n");
                }
            }
        }



        printf("MATRIZ INVERSA: \n");
        for(i = 0; i < linha; i++){

            for(j = 0; j < coluna; j++){

                printf ("%.2f",identidade[i][j]);  //print matriz inversa

                if(j < coluna - 1){

                    printf ("\t");

                }else{

                    printf("\n");
                }
            }
        }
    }
}
