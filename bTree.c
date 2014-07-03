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
    return(f->root==NULL);
}

int cheiaBTree(tBTree *f) {
    return BTREE_OPERACAO_OK;
}

int inserirBTree(tBTree *f, void *valor) {
    //TODO: testar
    tBTreeNode* aux = malloc(sizeof(tBTreeNode));
    aux->content = malloc(f->bytes);
    aux->father=aux->left=aux->right=NULL;
    memcpy(aux->content, valor, f->bytes);
    if(f->root==NULL) {
        f->root = aux;
    }
    else {
        char multiplier = isLittleEndian()?1:-1;
        int comparison;
        tBTreeNode **walk = &(f->root), *father;
        do {
            comparison=memcmp(*walk->content,valor,f->bytes)*multiplier;
            father=*walk;
            if(comparison<0) {
                walk=(&*walk->right);
            }
            else if (comparison>0)
            {
                walk=(&*walk->left);
            }
            else {
                return BTREE_OPERACAO_ERR;
            }
        }while(*walk!=NULL);
        aux->father=father;
        *walk=aux;
    }
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

int infoBTree(tBTreeNode* p, void *content); //retorna o conteúdo do nó

tBTreeNode* leftBTree(tBTreeNode* p); //retorna ponteiro para o nó filho da esq.

tBTreeNode* rightBTree(tBTreeNode* p); //retorna ponteiro para nó filho da direita

tBTreeNode* fatherBTree(tBTreeNode* p); //retorna ponteiro para o pai

tBTreeNode* brotherBTree(tBTreeNode* p); //retorna ponteiro para o nó irmão

int isLeftBTree(tBTreeNode* p); //retorna true se p é um filho esquerdo

int isRightBTree(tBTreeNode* p); //retorna true se p é um filho direito

int setLeftBTree(tBTreeNode* p, void *content); //define x um filho esq para p, com conteúdo x;

int setRightBTree(tBTreeNode* p, void *content); //define x um filho dir para p, com conteúdo x;
