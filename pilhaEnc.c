/* 
 * File:   pilhaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "pilhaEnc.h"

int inicializaPilhaEnc(tPilhaEnc *f) {
    if(f!=NULL) {
        f->head=f->tail=NULL;
        return PILHAENC_OPERACAO_OK;
    }
    return PILHAENC_OPERACAO_ERR;
}

int vaziaPilhaEnc(tPilhaEnc *f) {
    return (f->tail==NULL);
}

int cheiaPilhaEnc(tPilhaEnc *f) {
    return 0;
}

int pushPilhaEnc(tPilhaEnc *f, void* content, int bytes) {
    tPilhaEncItem *newVal = malloc(sizeof(tPilhaEncItem));
    newVal->content = malloc(bytes);
    memcpy(newVal->content,content,bytes);
    newVal->next=NULL;
    newVal->previous=f->tail;
    if(vaziaPilhaEnc(f))
        f->head=f->tail=newVal;
    else
        f->tail->next=f->tail=newVal;
    return PILHAENC_OPERACAO_OK;
}

int popPilhaEnc(tPilhaEnc *f, void* content, int bytes) {
    if(vaziaPilhaEnc(f))
        return PILHAENC_VAZIA;
    tPilhaEncItem *aux = f->tail;
    memcpy(content,aux->content,bytes);
    f->tail=f->tail->previous;
    free(aux->content);
    free(aux);
    return PILHAENC_OPERACAO_OK;
}

tPilhaEncItem* primeiroPilhaEnc(tPilhaEnc *f) {
    if (vaziaPilhaEnc(f))
        return NULL;
    return ((tPilhaEncItem*)f->head);
}

int tamanhoPilhaEnc(tPilhaEnc * f){
    if(vaziaPilhaEnc(f))
        return PILHAENC_VAZIA;
    unsigned int retorno=0;
    tPilhaEncItem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}
