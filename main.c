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
#include "listaEnc.h"
#include "bTree.h"

int main(int argc, char** argv) {
    //INICIALIZAÇÕES
    tFilaEnc *fe = malloc(sizeof(tFilaEnc));
    inicializaFilaEnc(fe,sizeof(int));
    tPilhaEnc *pe = malloc(sizeof(tPilhaEnc));
    inicializaPilhaEnc(pe,sizeof(int));
    tListaEnc *le = malloc(sizeof(tListaEnc));
    inicializaListaEnc(le,sizeof(int));
    tBTree *bt = malloc(sizeof(tBTree));
    inicializaBTree(bt,sizeof(int));
    //VARIÁVEIS AUXILIARES
    int ler;
    //MENUS
    do {
        printf("== MENU PRINCIPAL\n");
        printf("-->  1) Fila Enc\n");
        printf("-->  2) Pilha Enc\n");
        printf("-->  3) Lista Enc\n");
        printf("-->  4) Btree\n");
        printf("--> 99) Sair\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                menuFE(fe);
                break;
            case 2:
                menuPE(pe);
                break;
            case 3:
                menuLE(le);
                break;
            case 4:
                menuBT(bt);
                break;
        }
    }while(ler!=99);
    printf("Até logo! \\o/\n");
    printf("@AUTHOR: Fábio B. Tramasoli - IFRS POA - 0619132\n");
    printf("copyleft 2014 - https://github.com/tramasoli/ed1");
    //SANITIZAÇÃO
    finalizaBTree(bt);
    free(bt);
    finalizaFilaEnc(fe);
    free(fe);
    finalizaListaEnc(le);
    free(le);
    finalizaPilhaEnc(pe);
    free(pe);
    return (EXIT_SUCCESS);
}

//FUNÇÕES AUXILIARES

int menuFE(tFilaEnc *fe) {
    int ler;
    do {
        printf("== MENU FILA\n");
        printf("-->  1) Incluir\n");
        printf("-->  2) Excluir\n");
        printf("-->  3) Imprimir\n");
        printf("-->  4) Tamanho\n");
        printf("-->  5) Limpar\n");
        printf("--> 99) Voltar\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                printf("-->  1) Incluir / Informe o valor:\n");
                scanf("%d",&ler);
                inserirFilaEnc(fe,&ler);
                break;
            case 2:
                removerFilaEncSemValor(fe);
                break;
            case 3:
                printf("::: ITENS: %d\n",ler);
                printf("\n");
                break;
            case 4:
                ler=tamanhoFilaEnc(fe);
                printf("Tamanho: %d\n",ler);
                break;
            case 5:
                finalizaFilaEnc(fe);
                break;
        }
    }while(ler!=99);
}

int menuPE(tPilhaEnc *pe) {
    int ler;
    do {
        printf("== MENU PILHA\n");
        printf("-->  1) Incluir\n");
        printf("-->  2) Excluir\n");
        printf("-->  3) Imprimir\n");
        printf("-->  4) Tamanho\n");
        printf("-->  5) Limpar\n");
        printf("--> 99) Voltar\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                printf("-->  1) Incluir / Informe o valor:\n");
                scanf("%d",&ler);
                pushPilhaEnc(pe,&ler);
                break;
            case 2:
                break;
            case 3:
                printf("::: ITENS: %d\n",ler);
                printf("\n");
                break;
            case 4:
                ler=tamanhoPilhaEnc(pe);
                printf("Tamanho: %d\n",ler);
                break;
            case 5:
                finalizaPilhaEnc(pe);
                break;
        }
    }while(ler!=99);
}

int menuLE(tListaEnc *le) {
    int ler,ler2;
    do {
        printf("== MENU LISTA\n");
        printf("-->  1) Incluir\n");
        printf("-->  2) Excluir\n");
        printf("-->  3) Ler posicao\n");
        printf("-->  4) Imprimir\n");
        printf("-->  5) Tamanho\n");
        printf("-->  6) Limpar\n");
        printf("--> 99) Voltar\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                printf("-->  1) Incluir / Informe o valor:\n");
                scanf("%d",&ler);
                printf("-->  1) Incluir / Informe a posicao:\n");
                scanf("%d",&ler2);
                inserirListaEnc(le,ler2,&ler);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("::: ITENS: %d\n",ler);
                printf("\n");
                break;
            case 5:
                ler=tamanhoListaEnc(le);
                printf("Tamanho: %d\n",ler);
                break;
            case 6:
                finalizaListaEnc(le);
                break;
                
        }
    }while(ler!=99);
}

int menuBT(tBTree *bt) {
    int ler;
    tBTreeNode *tmp;
    do {
        printf("== MENU BTREE\n");
        printf("-->  1) Inserir valor\n");
        printf("-->  2) Excluir valor\n");
        printf("-->  3) Imprimir btree ordenada* (com bug para negativos)\n");
        printf("-->  4) Limpar\n");
        printf("--> 99) Voltar\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                printf("-->  1) Incluir / Informe o valor:\n");
                scanf("%d",&ler);
                inserirBTree(bt,&ler);
                break;
            case 2:
                printf("-->  2) Excluir / Informe o valor:\n");
                scanf("%d",&ler);
                findBtree(bt,&ler,&tmp);
                removerBTree(bt,tmp);
                break;
            case 3:
                printf("::: ITENS: ");
                sortedIntWalkBTree(bt->root,0);
                printf("\n");
                break;
            case 4:
                finalizaBTree(bt);
                break;
        }
    }while(ler!=99);
}