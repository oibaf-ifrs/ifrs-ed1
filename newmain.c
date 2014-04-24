/* 
 * File:   newmain.c
 * Author: 0619132
 *
 * Created on 24 de Abril de 2014, 09:10
 */

#include <stdio.h>
#include <stdlib.h>
#include "filaEnc.h"
#include "pilhaSeq.h"

/*
 * 
 * Execute: 
A. Em uma Pilha Sequencial "ps" de Float empilhe individualmente os dígitos de seu CPF.
B. remova os elementos e some-os dois a dois inserindo em uma fila encadeada de Float "fe"
C. remova os elementos da Fila, multiplicando-os e apresentado o resultado final.

Exemplo para o CPF: 123.456.789-01 temos:

Passo B: 1+0, 9+8, 7+6, 5+4, 3+2, 1. Portando devem ser enfileirados 1,17,13,9,5,1

Passo C: multiplicando teremos: 1*17*13*9*5*1=9945

1 - Alterar as estruturas para float (1,5pts)
2 - item A 1,0pt
3 - item B 1,0pt
4 - item C 0,5pt
5 - programa funcionar 1,0pt
 * 
 */
int main(int argc, char** argv) {
    float cpfArray[] = {0,0,7,6,3,4,5,5,0,5,9}, soma1, soma2, soma, multiplicacao;
    tPilha *ps = malloc(sizeof(tPilha));
    inicializaPilha(ps);
    tFila *fe = malloc(sizeof(tFila));
    inicializaFila(fe);
    //Item A
    int count=0;
    for (count=0;count<11; count++) {
        printf("%f\n",cpfArray[count]);
        pushPilha(ps,cpfArray[count]);
    }
    //Fim item A
    printf("\n\n\n");
    //Item B
    float aux=0;
    while (aux!=-1) {
        soma=0;
        soma1=popPilha(ps);
        if(soma1!=-1) {
            soma+=soma1;
            soma2=popPilha(ps);
            if(soma2!=-1)
                soma+=soma2;
            printf("Soma: %f\n",soma);
            inserirFila(fe,soma);
        } else
            aux=-1;
    }
    //Fim item B
    printf("\n\n\n");
    //Item C
    aux=0;
    multiplicacao=1;
    while(aux!=-1) {
        aux=removerFila(fe);
        if(aux!=-1)
            multiplicacao*=aux;
    }
    printf("Multiplicacao: %f\n",multiplicacao);
    //Fim item C
    //Limpezas
    free(ps);
    free(fe);
    return (EXIT_SUCCESS);
}

