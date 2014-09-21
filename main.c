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
    //Encadeados
    tFilaEnc *fe = malloc(sizeof(tFilaEnc));
    inicializaFilaEnc(fe,sizeof(int));
    tPilhaEnc *pe = malloc(sizeof(tPilhaEnc));
    inicializaPilhaEnc(pe,sizeof(int));
    tListaEnc *le = malloc(sizeof(tListaEnc));
    inicializaListaEnc(le,sizeof(int));
    tBTree *bt = malloc(sizeof(tBTree));
    inicializaBTree(bt,sizeof(int),1);
    //Sequenciais
    tFilaSeq *fs=malloc(sizeof(tFilaSeq));
    inicializaFilaSeq(fs,sizeof(int));
    tPilhaSeq *ps=malloc(sizeof(tPilhaSeq));
    inicializaPilhaSeq(ps,sizeof(int));
    tListaSeq *ls=malloc(sizeof(tListaSeq));
    inicializaListaSeq(ls,sizeof(int));
    //VARIÁVEIS AUXILIARES
    int ler;
    //MENUS
    do {
        printf("== MENU PRINCIPAL\n");
        printf("-->  1) Fila Enc\n");
        printf("-->  2) Pilha Enc\n");
        printf("-->  3) Lista Enc\n");
        printf("-->  4) Btree\n");
        printf("-->  5) Fila Seq\n");
        printf("-->  6) Pilha Seq*\n");
        printf("-->  7) Lista Seq*\n");
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
            case 5:
                menuFS(fs);
                break;
            case 6:
                menuPS(ps);
                break;
            case 7:
                menuLS(ls);
                break;
        }
    }while(ler!=99);
    printf("Até logo! \\o/\n");
    printf("@AUTHOR: Fábio B. Tramasoli - IFRS POA - 0619132\n");
    printf("copyleft 2014 - https://github.com/tramasoli/ed1");
    //SANITIZAÇÃO
    //Encadeados
    finalizaBTree(bt);
    free(bt);
    finalizaFilaEnc(fe);
    free(fe);
    finalizaListaEnc(le);
    free(le);
    finalizaPilhaEnc(pe);
    free(pe);
    //Sequenciais
    finalizaFilaSeq(fs);
    free(fs);
    finalizaListaSeq(ls);
    free(ls);
    finalizaPilhaSeq(ps);
    free(ps);
    return (EXIT_SUCCESS);
}

//FUNÇÕES AUXILIARES

int menuFE(tFilaEnc *fe) {
    int ler,aux;
    tFilaIEnctem *fei;
    do {
        printf("== MENU FILA ENC\n");
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
                if(removerFilaEnc(fe,&aux)==FILAENC_OPERACAO_OK)
                    printf("-->  2) Excluir / Excluído o valor %d",aux);
                else
                    printf("**ERRO** fila vazia");
                break;
            case 3:
                printf("::: ITENS: ");
                for(fei=fe->head;fei!=NULL;fei=fei->next) {
                    aux=*((int *)(fei->content));
                    printf("%d,",aux);
                }
                break;
            case 4:
                ler=tamanhoFilaEnc(fe);
                printf("Tamanho: %d",ler);
                break;
            case 5:
                finalizaFilaEnc(fe);
                break;
        }
        printf("\n");
    }while(ler!=99);
}

int menuFS(tFilaSeq *fe) {
    int ler,aux;
    do {
        printf("== MENU FILA SEQ\n");
        printf("-->  1) Incluir\n");
        printf("-->  2) Excluir\n");
        printf("-->  3) Imprimir primeiro\n");
        printf("-->  4) Tamanho\n");
        printf("-->  5) Limpar\n");
        printf("--> 99) Voltar\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                printf("-->  1) Incluir / Informe o valor:\n");
                scanf("%d",&ler);
                if(inserirFilaSeq(fe,&ler)==FILASEQ_OPERACAO_ERR)
                    printf("**ERRO** fila cheia");
                break;
            case 2:
                if(removerFilaSeq(fe,&aux)==FILAENC_OPERACAO_OK)
                    printf("-->  2) Excluir / Excluído o valor %d",aux);
                else
                    printf("**ERRO** fila vazia");
                break;
            case 3:
                if(topoFilaSeq(fe,&aux)!=FILASEQ_OPERACAO_ERR)
                    printf("::: TOPO: %d",aux);
                else
                    printf("**ERRO** fila vazia");
                break;
            case 4:
                ler=tamanhoFilaSeq(fe);
                printf("Tamanho: %d",ler);
                break;
            case 5:
                finalizaFilaSeq(fe);
                inicializaFilaSeq(fe,fe->bytes);
                break;
        }
        printf("\n");
    }while(ler!=99);
}

int menuPE(tPilhaEnc *pe) {
    int ler,aux;
    tPilhaEncItem *pei;
    do {
        printf("== MENU PILHA ENC\n");
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
                if(popPilhaEnc(pe,&aux)==PILHAENC_OPERACAO_OK)
                    printf("-->  2) Excluir / Excluído o valor %d",aux);
                else
                    printf("**ERRO** pilha vazia");
                break;
            case 3:
                printf("::: TOPO: ");
                for(pei=pe->tail;pei!=NULL;pei=NULL) {
                    aux=*((int *)(pei->content));
                    printf("%d,",aux);
                }
                break;
            case 4:
                ler=tamanhoPilhaEnc(pe);
                printf("Tamanho: %d",ler);
                break;
            case 5:
                finalizaPilhaEnc(pe);
                break;
        }
        printf("\n");
    }while(ler!=99);
}

int menuPS(tPilhaSeq *pe) {
    int ler,aux;
    do {
        printf("== MENU PILHA SEQ\n");
        printf("-->  1) Incluir\n");
        printf("-->  2) Excluir\n");
        printf("-->  3) Imprimir topo\n");
        printf("-->  4) Tamanho\n");
        printf("-->  5) Limpar\n");
        printf("--> 99) Voltar\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                printf("-->  1) Incluir / Informe o valor:\n");
                scanf("%d",&ler);
                if(pushPilhaSeq(pe,&ler)==PILHASEQ_OPERACAO_ERR)
                    printf("**ERRO** pilha cheia");
                break;
            case 2:
                if(popPilhaSeq(pe,&aux)==PILHASEQ_OPERACAO_OK)
                    printf("-->  2) Excluir / Excluído o valor %d",aux);
                else
                    printf("**ERRO** pilha vazia");
                break;
            case 3:
                if(primeiroPilhaSeq(pe,&aux)!=PILHASEQ_OPERACAO_ERR)
                    printf("::: TOPO: %d",aux);
                else
                    printf("**ERRO** pilha vazia");
                break;
            case 4:
                ler=tamanhoPilhaSeq(pe);
                printf("Tamanho: %d",ler);
                break;
            case 5:
                finalizaPilhaSeq(pe);
                inicializaPilhaSeq(pe,pe->bytes);
                break;
        }
        printf("\n");
    }while(ler!=99);
}

int menuLE(tListaEnc *le) {
    int ler,aux,ler2;
    tListaEncItem *tmp;
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
                scanf("%d",&aux);
                inserirListaEnc(le,aux,&ler);
                break;
            case 2:
                printf("-->  2) Excluir / Informe a posição:\n");
                scanf("%d",&ler2);
                if(removerListaEnc(le,ler2,&aux)==LISTAENC_OPERACAO_OK)
                    printf("-->  2) Excluir / Excluído o valor %d",aux);
                else
                    printf("**ERRO** Lista vazia");
                break;
            case 3:
                printf("-->  3) Ler posição / Informe a posição:\n");
                scanf("%d",&ler2);
                if(elementoListaEnc(le,ler2,&aux)==LISTAENC_OPERACAO_OK)
                    printf("-->  3) Ler posição / O valor é %d",aux);
                else
                    printf("**ERRO** Lista vazia");
                break;
            case 4:
                printf("::: ITENS: ");
                for(tmp=le->head;tmp!=NULL;tmp=tmp->next) {
                    aux=*((int *)(tmp->content));
                    printf("%d,",aux);
                }
                break;
            case 5:
                ler=tamanhoListaEnc(le);
                printf("Tamanho: %d",ler);
                break;
            case 6:
                finalizaListaEnc(le);
                break;
        }
        printf("\n");
    }while(ler!=99);
}

int menuLS(tListaSeq *le) {
    int ler,aux,ler2;
    do {
        printf("== MENU LISTA SEQ\n");
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
                scanf("%d",&aux);
                inserirListaSeq(le,aux,&ler);
                break;
            case 2:
                printf("-->  2) Excluir / Informe a posição:\n");
                scanf("%d",&ler2);
                if(removerListaSeq(le,ler2,&aux)==LISTASEQ_OPERACAO_OK)
                    printf("-->  2) Excluir / Excluído o valor %d",aux);
                else
                    printf("**ERRO** Lista vazia");
                break;
            case 3:
                printf("-->  3) Ler posição / Informe a posição:\n");
                scanf("%d",&ler2);
                if(elementoListaSeq(le,ler2,&aux)==LISTASEQ_OPERACAO_OK)
                    printf("-->  3) Ler posição / O valor é %d",aux);
                else
                    printf("**ERRO** Lista vazia");
                break;
            case 4:
                printf("::: ITENS: ");
                for(aux=0;aux<tamanhoListaSeq(le);aux++) {
                    elementoListaSeq(le, aux+1, &ler2);
                    printf("%d,",ler2);
                }
                break;
            case 5:
                ler=tamanhoListaSeq(le);
                printf("Tamanho: %d",ler);
                break;
            case 6:
                finalizaListaSeq(le);
                inicializaListaSeq(le,le->bytes);
                break;
        }
        printf("\n");
    }while(ler!=99);
}

int menuBT(tBTree *bt) {
    int ler,aux;
    tBTreeNode *tmp;
    do {
        printf("== MENU BTREE\n");
        printf("-->  1) Inserir valor\n");
        printf("-->  2) Excluir valor\n");
        printf("-->  3) Imprimir btree ordenada* (com bug para negativos!!)\n");
        printf("-->  4) Limpar\n");
        printf("--> 99) Voltar\n");
        scanf("%d",&ler);
        switch(ler) {
            case 1:
                printf("-->  1) Incluir / Informe o valor:\n");
                scanf("%d",&ler);
                if(inserirBTree(bt,&ler)==BTREE_OPERACAO_ERR)
                    printf("**ERRO** valor já existe!");
                break;
            case 2:
                printf("-->  2) Excluir / Informe o valor:\n");
                scanf("%d",&ler);
                findBtree(bt,&ler,&tmp);
                removerBTree(bt,tmp);
                break;
            case 3:
                printf("::: ITENS: ");
                sortedIntWalkBTree(bt->root,0,"%d,");
                break;
            case 4:
                finalizaBTree(bt);
                break;
        }
        printf("\n");
    }while(ler!=99);
}