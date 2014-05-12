/* 
 * File:   pilhaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "pilhaEnc.h"

int inicializaPilhaEnc(tPilhaEnc *f, int bytes) {
    if(f!=NULL) {
        f->head=f->tail=NULL;
        f->bytes=bytes;
        return PILHAENC_OPERACAO_OK;
    }
    return PILHAENC_OPERACAO_ERR;
}

int finalizaPilhaEnc(tPilhaEnc * f) {
    char *aux = malloc(f->bytes);
    while (popPilhaEnc(f,aux)!=PILHAENC_VAZIA) {
    }
    free(aux);
    //TODO: implementar melhor
    return PILHAENC_OPERACAO_OK;
}

int vaziaPilhaEnc(tPilhaEnc *f) {
    if (f->tail==NULL)
        return PILHAENC_VAZIA;
    else
        return PILHAENC_OPERACAO_OK;
}

int cheiaPilhaEnc(tPilhaEnc *f) {
    return PILHAENC_OPERACAO_OK;
}

int pushPilhaEnc(tPilhaEnc *f, void* content) {
    tPilhaEncItem *newVal = malloc(sizeof(tPilhaEncItem));
    newVal->content = malloc(f->bytes);
    memcpy(newVal->content,content,f->bytes);
    newVal->next=NULL;
    newVal->previous=f->tail;
    if(vaziaPilhaEnc(f)==PILHAENC_VAZIA)
        f->head=f->tail=newVal;
    else
        f->tail->next=f->tail=newVal;
    return PILHAENC_OPERACAO_OK;
}

int popPilhaEnc(tPilhaEnc *f, void* content) {
    if(vaziaPilhaEnc(f)==PILHAENC_VAZIA)
        return PILHAENC_VAZIA;
    tPilhaEncItem *aux = f->tail;
    memcpy(content,aux->content,f->bytes);
    f->tail=f->tail->previous;
    free(aux->content);
    free(aux);
    return PILHAENC_OPERACAO_OK;
}

tPilhaEncItem* primeiroPilhaEnc(tPilhaEnc *f) {
    if (vaziaPilhaEnc(f)==PILHAENC_VAZIA)
        return NULL;
    return ((tPilhaEncItem*)f->head);
}

int tamanhoPilhaEnc(tPilhaEnc * f){
    if(vaziaPilhaEnc(f)==PILHAENC_VAZIA)
        return 0;
    unsigned int retorno=0;
    tPilhaEncItem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}
