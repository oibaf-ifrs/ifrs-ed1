#include <stdlib.h>
#include "pilhaSeq.h"

void inicializaPilha(tPilha *f) {
    f->head=f->tail=NULL;
}

int vaziaPilha(tPilha *f) {
    return (f->tail==NULL);
}

int cheiaPilha(tPilha *f) {
    return 0;
}

int pushPilha(tPilha *f, abstractContent valor) {
    tPilhaItem *newVal = malloc(sizeof(tPilhaItem));
    newVal->content = valor;
    newVal->next=NULL;
    newVal->previous=f->tail;
    if(vaziaPilha(f))
        f->head=f->tail=newVal;
    else
        f->tail->next=f->tail=newVal;
    return 1;
}

abstractContent popPilha(tPilha *f) {
    if(vaziaPilha(f))
        return -1;
    tPilhaItem *aux = f->tail;
    abstractContent retorno = aux->content;
    f->tail=f->tail->previous;
    free(aux);
    return retorno;
}

tPilhaItem* primeiroPilha(tPilha *f) {
    if (vaziaPilha(f))
        return NULL;
    return ((tPilhaItem*)f->head);
}

int tamanhoPilha(tPilha * f){
    if(vaziaPilha(f))
        return 0;
    unsigned int retorno=0;
    tPilhaItem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}


