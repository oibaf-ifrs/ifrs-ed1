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
    while(removerBTree(f,f->root)==BTREE_OPERACAO_OK) {
    }
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
        return BTREE_OPERACAO_OK;
    }
    else {
        char multiplier = isLittleEndian()?1:-1;
        int comparison;
        tBTreeNode **walk = &(f->root), *father;
        do {
            comparison=memcmp((*walk)->content,valor,f->bytes)*multiplier;
            father=*walk;
            if(comparison<0) {
                walk=&((*walk)->right);
            }
            else if (comparison>0)
            {
                walk=&((*walk)->left);
            }
            else {
                return BTREE_OPERACAO_ERR;
            }
        }while(*walk!=NULL);
        aux->father=father;
        *walk=aux;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int removerBTree(tBTree *f, tBTreeNode *toRemove) {
    if(!vaziaBTree(f) && toRemove!=NULL) {
        tBTreeNode *aux;
        if(toRemove->left!=NULL && toRemove->right!=NULL) {
            if(biggerBTree(toRemove->left,&aux)==BTREE_OPERACAO_OK) {
                memcpy(toRemove->content,aux->content,f->bytes);
                return removerBTree(f,aux);
            }
        }
        else if(toRemove->left==NULL && toRemove->right==NULL) {
            if(toRemove->father==NULL)
                f->root = NULL;
            else {
                if(((tBTreeNode*)toRemove->father)->left==toRemove)
                    ((tBTreeNode*)toRemove->father)->left=NULL;
                else
                    ((tBTreeNode*)toRemove->father)->right=NULL;
            }
            free(toRemove->content);
            free(toRemove);
        }
        else {
            aux=((toRemove->left!=NULL)?toRemove->left:toRemove->right);
            if(f->root==toRemove)
                f->root=aux;
            aux->father=toRemove->father;
            if(toRemove->father!=NULL) {
                if(((tBTreeNode*)toRemove->father)->left==toRemove)
                    ((tBTreeNode*)toRemove->father)->left=aux;
                else
                    ((tBTreeNode*)toRemove->father)->right=aux;
            }
            free(toRemove->content);
            free(toRemove);
        }
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int removerBTreeSemValor(tBTree *f) {
    //TODO: implementar
}

int infoBTree(tBTreeNode* p, void *content, int bytes) {
    if(p!=NULL) {
        memcpy(content,p->content,bytes);
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int findBtree(tBTree *f, void *valor, tBTreeNode** node) {
    if(f!=NULL && f->root!=NULL) {
        char multiplier = isLittleEndian()?1:-1;
        int comparison;
        tBTreeNode **walk = &(f->root), *father;
        do {
            comparison=memcmp((*walk)->content,valor,f->bytes)*multiplier;
            father=*walk;
            if(comparison<0) {
                walk=&((*walk)->right);
            }
            else if (comparison>0)
            {
                walk=&((*walk)->left);
            }
            else {
                *node=*walk;
                return BTREE_OPERACAO_OK;
            }
        }while(*walk!=NULL);
    }
    return BTREE_OPERACAO_ERR;
}

int leftBTree(tBTreeNode* p, tBTreeNode* node) {
    if(p!=NULL) {
        node = p->left;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int rightBTree(tBTreeNode* p, tBTreeNode* node) {
    if(p!=NULL) {
        node = p->right;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int fatherBTree(tBTreeNode* p, tBTreeNode* node) {
    if(p!=NULL) {
        node = p->father;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int brotherBTree(tBTreeNode* p, tBTreeNode* node) {
    tBTreeNode *retorno=((tBTreeNode*)(p->father));
    if(p!=NULL && p->father!=NULL) {
        node = (retorno->left==p)?retorno->right:retorno->left;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int biggerBTree(tBTreeNode* p, tBTreeNode** node) {
    if(p!=NULL) {
        tBTreeNode *aux=p;
        while(p->right!=NULL)
            p=p->right;
        *node=p;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int isLeftBTree(tBTreeNode* p); //retorna true se p é um filho esquerdo - em relação a quem???

int isRightBTree(tBTreeNode* p); //retorna true se p é um filho direito - em relação a quem???

int setLeftBTree(tBTreeNode* p, void *content, int bytes) {
    if(p!=NULL) {
        tBTreeNode* new = malloc(sizeof(tBTreeNode));
        new->content=malloc(bytes);
        memcpy(new->content,content,bytes);
        p->left = new;
        new->father = p;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int setRightBTree(tBTreeNode* p, void *content, int bytes) {
    if(p!=NULL) {
        tBTreeNode* new = malloc(sizeof(tBTreeNode));
        new->content=malloc(bytes);
        memcpy(new->content,content,bytes);
        p->right = new;
        new->father = p;
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}

int sortedIntWalkBTree(tBTreeNode* p, int level) {
    if(p!=NULL) {
        int *content=p->content, count;
        sortedIntWalkBTree(p->left,level+1);
        /*
        for(count=0;count<level;count++)
            printf(".");
        */
        printf("%d",(*content));
        sortedIntWalkBTree(p->right,level+1);
        return BTREE_OPERACAO_OK;
    }
    return BTREE_OPERACAO_ERR;
}