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
#include "bTree.h"

int main(int argc, char** argv) {
    tBTree *ls = malloc(sizeof(tBTree));
    tBTreeNode *temp;
    int tempint=5;
    inicializaBTree(ls,sizeof(int));
    int count;
    for(count=5;count<10;count++)
        inserirBTree(ls,&count);
    for(count=0;count<5;count++)
        inserirBTree(ls,&count);
    printf("walk1:");
    sortedIntWalkBTree(ls->root,0);
    findBtree(ls,&tempint,&temp);
    removerBTree(ls,temp);
    printf("\nwalk2:");
    sortedIntWalkBTree(ls->root,0);
    finalizaBTree(ls);
    printf("\nwalk3:");
    sortedIntWalkBTree(ls->root,0);
    free(ls);
    return (EXIT_SUCCESS);
}

