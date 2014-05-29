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
    float aux;
    unsigned char count,key=65;
    tListaSeq *ls = malloc(sizeof(tListaSeq));
    inicializaListaSeq(ls,sizeof(float));
    //Item A
    while (key!=99) {
        printf("EDITOR DE LISTAS\n");
        printf("1 – EXIBIR LISTA\n");
        printf("2 – INSERIR\n");
        printf("3 – REMOVER\n");
        printf("4 – EXIBIR ELEMENTO\n");
        printf("5 – EXIBIR POSIÇÃO\n");
        printf("6 – ESVAZIAR\n");
        printf("99 – SAIR\n");
        scanf("%hhu",&key);
        switch(key) {
            case 1:
                for (count=0;count<tamanhoListaSeq(ls); count++) {
                    if(elementoListaSeq(ls,count+1,&aux)==LISTASEQ_OPERACAO_OK)
                        printf("=> Lista[%d] = %f\n",count+1,aux);
                }
                break;
            case 2:
                printf("Informe o indice e o valor:\n");
                scanf("%hhu",&count);
                scanf("%f",&aux);
                inserirListaSeq(ls,count,&aux);
                break;
            case 3:
                printf("Informe o indice:\n");
                scanf("%hhu",&count);
                if(removerListaSeq(ls,count,&aux) == LISTASEQ_OPERACAO_ERR)
                    printf("** [ERRO] **\n");
                break;
            case 4:
                printf("Informe o indice:\n");
                scanf("%hhu",&count);
                if (elementoListaSeq(ls,count,&aux) != LISTASEQ_OPERACAO_ERR)
                    printf("Valor: %f\n",aux);
                else
                    printf("** [ERRO] **\n");
                break;
            case 5:
                printf("Informe o valor:\n");
                scanf("%f",&aux);
                count=posicaoListaSeq(ls,&aux);
                printf("Posicao: %hhu\n",count);
                break;
            case 6:
                for (count=0;count<tamanhoListaSeq(ls); count++) {
                    removerListaSeq(ls,1,&aux);
                }
                break;
        }
    } ;
    finalizaListaSeq(ls);
    free(ls);
    return (EXIT_SUCCESS);
}

