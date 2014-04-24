#include <stdlib.h>
#include "filaEnc.h"

void inicializaFila(tFila *f) {
    f->head=f->tail=NULL;
}

int vaziaFila(tFila *f) {
    return (f->head==NULL);
}

int cheiaFila(tFila *f) {
    return 0;
}

int inserirFila(tFila *f, abstractContent valor) {
    tFilaItem *newVal = malloc(sizeof(tFilaItem));
    newVal->content = valor;
    newVal->next=NULL;
    if(vaziaFila(f))
        f->head=f->tail=newVal;
    else
        f->tail->next=f->tail=newVal;
    return 1;
}

abstractContent removerFila(tFila *f) {
    if(vaziaFila(f))
        return -1;
    tFilaItem *aux = f->head;
    abstractContent retorno = aux->content;
    f->head=f->head->next;
    free(aux);
    return retorno;
}

tFilaItem* primeiroFila(tFila *f) {
    if (vaziaFila(f))
        return NULL;
    return ((tFilaItem*)f->head);
}

int tamanhoFila(tFila * f){
    if(vaziaFila(f))
        return 0;
    unsigned int retorno=0;
    tFilaItem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}

