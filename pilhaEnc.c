/* 
 * File:   pilhaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "pilhaEnc.h"

void inicializaPilha(tPilha *f) {
    if(f!=NULL) {
        f->head=f->tail=NULL;
        return PILHA_OPERACAO_OK;
    }
    return PILHA_OPERACAO_ERR;
}

int vaziaPilha(tPilha *f) {
    return (f->tail==NULL);
}

int cheiaPilha(tPilha *f) {
    return 0;
}

int pushPilha(tPilha *f, void* content, int bytes) {
    tPilhaItem *newVal = malloc(sizeof(tPilhaItem));
    newVal->content = malloc(bytes);
    memcpy(newVal->content,content,bytes);
    newVal->next=NULL;
    newVal->previous=f->tail;
    if(vaziaPilha(f))
        f->head=f->tail=newVal;
    else
        f->tail->next=f->tail=newVal;
    return PILHA_OPERACAO_OK;
}

int popPilha(tPilha *f, void* content, int bytes) {
    if(vaziaPilha(f))
        return PILHA_VAZIA;
    tPilhaItem *aux = f->tail;
    memcpy(content,aux->content,bytes);
    f->tail=f->tail->previous;
    free(aux);
    return PILHA_OPERACAO_OK;
}

tPilhaItem* primeiroPilha(tPilha *f) {
    if (vaziaPilha(f))
        return NULL;
    return ((tPilhaItem*)f->head);
}

int tamanhoPilha(tPilha * f){
    if(vaziaPilha(f))
        return PILHA_VAZIA;
    unsigned int retorno=0;
    tPilhaItem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}
