/* Programa norep.c
 * Imprime 100 linhas, cada uma contendo numeros aleatorios
 * de 0 a 5 sem repeticao
 * 
 * Autor:   Renan Vicente
 * Data:    14/03/2017
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 6 /* limite maximo do valor a ser sorteado */
#define LINHAS 100 /* maximo de linhas */

int sortear(void); /* sorteia um numero aleatorio */

int main(void)
{
    int j, k, t; /* variaveis auxiliares */
    int contador; /* conta quantos numeros validos(sem repeticao) ja foram obtidos numa linha */
    int verifica; /* verifica se um numero sorteado e repetido ou nao */
    int sorteados[MAX]; /* vetor que armazena os numeros sorteados (sem repeticao) de uma linha */

    srand((unsigned)time(NULL));
    for(j=0; j<LINHAS; j++)
    {
        for(k=0; k<MAX; k++)
        {
            sorteados[k] = MAX+1; /* preenche a caixa de numeros com valores fora do intervalo de valores sorteados */
        }
        printf("\n");
        contador = 0; /* zera a quantidade de numeros sorteados para iniciar uma nova linha */
        do
        {
            t = sortear();
            verifica = 0; /* usada para verificar se um numero ja foi sorteado em uma linha */
            for(k=0; k<MAX; k++)
            {
                if(t == sorteados[k])
                {
                    verifica = 1;
                }
            }
            if(!verifica)
            {
                sorteados[contador] = t;
                contador++;
            }
        }while(contador < MAX);
        for(k=0; k<MAX; k++)
        {
            printf("%d",sorteados[k]);
            printf("    ");
        }
        printf("\n");
    }
    return 0;
}

int sortear(void)
{
    int x;
    x = rand() % MAX;
    return x;
}
