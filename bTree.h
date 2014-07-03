/* 
 * File:   FilaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: bTree agnóstica a tipos.
 * 
 */

#define BTREE_VAZIA -1
#define BTREE_CHEIA 10
#define BTREE_OPERACAO_OK 0
#define BTREE_OPERACAO_ERR 1

typedef struct{
    void *content;
    void *left;
    void *right;
}tBTreeNode;

typedef struct{
    tBTreeNode *root;
    int bytes;
}tBTree;

int inicializaBTree(tBTree *f, int bytes);

int finalizaBTree(tBTree *f);

int vaziaBTree(tBTree *f);

int cheiaBTree(tBTree *f);

int inserirBTree(tBTree *f, void *valor);

int removerBTree(tBTree *f, void *content);

int removerBTreeSemValor(tBTree *f);

tFilaIEnctem* primeiroBTree(tBTree *f);

int tamanhoBTree(tBTree * f);