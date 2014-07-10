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
    void *father;
}tBTreeNode;

typedef struct{
    tBTreeNode *root;
    int bytes;
    int negative;
}tBTree;

int inicializaBTree(tBTree *f, int bytes, int negative);

int finalizaBTree(tBTree *f);

int vaziaBTree(tBTree *f);

int cheiaBTree(tBTree *f);

int inserirBTree(tBTree *f, void *valor);

int removerBTree(tBTree *f, tBTreeNode *toRemove);

int removerBTreeSemValor(tBTree *f);

int infoBTree(tBTreeNode* p, void *content, int bytes); //retorna o conteúdo do nó

int findBtree(tBTree *f, void *valor, tBTreeNode** node); //retorna o ponteiro que contem o conteúdo

int leftBTree(tBTreeNode* p, tBTreeNode* node); //retorna ponteiro para o nó filho da esq.

int rightBTree(tBTreeNode* p, tBTreeNode* node); //retorna ponteiro para nó filho da direita

int fatherBTree(tBTreeNode* p, tBTreeNode* node); //retorna ponteiro para o pai

int brotherBTree(tBTreeNode* p, tBTreeNode* node); //retorna ponteiro para o nó irmão

int biggerBTree(tBTreeNode* p, tBTreeNode** node); //retorna ponteiro para maior na subarvore

int isLeftBTree(tBTreeNode* p); //retorna true se p é um filho esquerdo

int isRightBTree(tBTreeNode* p); //retorna true se p é um filho direito

int setLeftBTree(tBTreeNode* p, void *content, int bytes); //define x um filho esq para p, com conteúdo x;

int setRightBTree(tBTreeNode* p, void *content, int bytes); //define x um filho dir para p, com conteúdo x;

int sortedIntWalkBTree(tBTreeNode* p, int level, char* format);