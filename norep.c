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
    double quantidade[MAX]; /* conta quantas vezes cada numero foi sorteado, inclusive as repeticoes */
    double somatorio = 0; /* somatorio de sorteios */
    double p; /* porcentagem de sorteio de cada numero */
    
    srand((unsigned)time(NULL));
    for(j=0; j<MAX; j++)
    {
        quantidade[j] = 0; /* inicialmente nenhum numero foi sorteado ainda, por isso todos ficam igual a zero */
    }
    for(j=0; j<LINHAS; j++) /* controla quantas linhas serao processadas e impressas */
    {
        for(k=0; k<MAX; k++)
            sorteados[k] = MAX+1; /* preenche a caixa de numeros com valores fora do intervalo de valores sorteados */
        printf("\n");
        contador = 0; /* zera a quantidade de numeros sorteados para iniciar uma nova linha */
        do
        {
            t = sortear();
            /* printf("Numero sorteado: %d\n", t); */
            for(k=0; k<MAX; k++)
                if(t == k)
                    quantidade[k] += 1; /* incrementa a quantidade de vezes que cada numero e' sorteado */ 
            verifica = 0; /* usada para verificar se um numero ja foi sorteado em uma linha */
            for(k=0; k<MAX; k++)
                if(t == sorteados[k]) /* se o numero que foi sorteado agora e' igual a um dos numeros ja sorteados na linha atual */
                    verifica = 1; /* atribue 1 para nao entrar na condicao abaixo */
            if(!verifica) /* se <verifica> ainda estiver igual a zero, significa que o numero sorteado nao e repetido, entao sera aceito" */
            {
                sorteados[contador] = t; /* o numero e guardado no vetor de numeros desta linha */
                contador++; /* o contador passa para o proximo elemento deste vetor */
            }
        }while(contador < MAX); /* ate atingir o maximo de numeros por linha */
        for(k=0; k<MAX; k++)
        {
            printf("%d",sorteados[k]); /* terminados o numero maximo de cada linha, imprime a linha e se inicia outra linha */
            printf("    ");
        }
        printf("\n");
    }
    for(k=0; k<MAX; k++)
        somatorio += quantidade[k]; /* faz o somatorio da quantidade de sorteios de todos os numeros */
    for(k=0; k<MAX; k++)
    {
        p = (quantidade[k]*100)/somatorio;
        printf("O numero %d foi sorteado %.0f vezes (%f%%)\n", k, quantidade[k], p); /* mostra quantas vezes cada numero foi sorteado e a porcentagem */
    }
    return 0;
}

int sortear(void)
{
    int x;
    x = rand() % MAX;
        return x;
}

