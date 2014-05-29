/* 
 * File:   newmain.c
 * Author: 0619132
 *
 * Created on 24 de Abril de 2014, 09:10
 */

#include <stdio.h>
#include <stdlib.h>
#include "filaEnc.h"
#include "filaSeq.h"
#include "pilhaEnc.h"
#include "pilhaSeq.h"
#include "listaSeq.h"

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
    float cpfArray[] = {0,0,7,6,3,4,5,5,0,5,9}, aux;
    tListaSeq *ls = malloc(sizeof(tListaSeq));
    inicializaListaSeq(ls,sizeof(float));
    //Item A
    int count=0;
    for (count=0;count<11; count++) {
        printf("%f\n",cpfArray[count]);
        inserirListaSeq(ls,count+1,cpfArray+count);
    }
    //Fim item A
    printf("\nFim item A\n");
    aux=12;
    inserirListaSeq(ls,4,&aux);
    for (count=0;count<tamanhoListaSeq(ls); count++) {
        if(elementoListaSeq(ls,count+1,&aux)==LISTASEQ_OPERACAO_OK)
            printf("%f\n",aux);
    }
    printf("\nFim item B\n");
    removerListaSeq(ls,4,&aux);
    removerListaSeq(ls,11,&aux);
    removerListaSeq(ls,1,&aux);
    for (count=0;count<tamanhoListaSeq(ls); count++) {
        if(elementoListaSeq(ls,count+1,&aux)==LISTASEQ_OPERACAO_OK)
            printf("%f\n",aux);
    }
    printf("\nFim item C\n");
    //Limpezas
    finalizaListaSeq(ls);
    free(ls);
    return (EXIT_SUCCESS);
}

