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
#include "listaEnc.h"

int main(int argc, char** argv) {
    tListaEnc *ls = malloc(sizeof(tListaEnc));
    int count,aux=5;
    inicializaListaEnc(ls,sizeof(int));
    for(count=1;count<11;count++)
        inserirListaEnc(ls,count,&count);
    posicaoListaEnc(ls,&aux);
    printf("%d\n\n",aux);
    removerListaEnc(ls,8,&aux);
    for(count=1;count<11;count++) {
        if(elementoListaEnc(ls,count,&aux)!=LISTAENC_OPERACAO_ERR)
            printf("%d\n",aux);
    }
    finalizaListaEnc(ls);
    free(ls);
    return (EXIT_SUCCESS);
}

