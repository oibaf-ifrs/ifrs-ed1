/* 
 * File:   BTree.c
 * Author: Fábio Tramasoli (0619132)
 * About: bTree agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "auxFunc.h"
#include "bTree.h"

int inicializaBTree(tBTree *f, int bytes) {
    if(f!=NULL) {
        f->root=NULL;
        f->bytes=bytes;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int finalizaBTree(tBTree *f) {
    //TODO: implementar
    char *aux = malloc(f->bytes);
    while(removerBTree(f,aux)==BTREE_OPERACAO_OK) {
    }
    free(aux);
    return BTREE_OPERACAO_OK;
}

int vaziaBTree(tBTree *f) {
    //TODO: implementar
}

int cheiaBTree(tBTree *f) {
    return BTREE_OPERACAO_OK;
}

int inserirBTree(tBTree *f, void *valor) {
    //TODO: implementar
}

int removerBTree(tBTree *f, void *content) {
    //TODO: implementar
}

int removerBTreeSemValor(tBTree *f) {
    //TODO: implementar
}

tFilaIEnctem* primeiroBTree(tBTree *f) {
    //TODO: implementar
}

int tamanhoBTree(tBTree * f){
    //TODO: implementar
}
