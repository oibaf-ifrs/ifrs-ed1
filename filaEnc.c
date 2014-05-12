/* 
 * File:   FilaEnc.c
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "filaEnc.h"

int inicializaFilaEnc(tFilaEnc *f, int bytes) {
    if(f!=NULL) {
        f->head=f->tail=NULL;
        f->bytes=bytes;
        return FILAENC_OPERACAO_OK;
    }
    return FILAENC_OPERACAO_ERR;
}

int finalizaFilaEnc(tFilaEnc *f) {
    char *aux = malloc(f->bytes);
    while(removerFilaEnc(f,aux)==FILAENC_OPERACAO_OK) {
    }
    free(aux);
    return FILAENC_OPERACAO_OK;
}

int vaziaFilaEnc(tFilaEnc *f) {
    if (f->head==NULL)
        return FILAENC_VAZIA;
    else
        return FILAENC_OPERACAO_OK;
}

int cheiaFilaEnc(tFilaEnc *f) {
    return FILAENC_OPERACAO_OK;
}

int inserirFilaEnc(tFilaEnc *f, void *valor) {
    tFilaIEnctem *newVal = malloc(sizeof(tFilaIEnctem));
    newVal->content = malloc(f->bytes);
    memcpy(newVal->content, valor, f->bytes);
    newVal->next=NULL;
    if(vaziaFilaEnc(f))
        f->head=f->tail=newVal;
    else 
        f->tail->next=f->tail=newVal;
    return FILAENC_OPERACAO_OK;
}

int removerFilaEnc(tFilaEnc *f, void *content) {
    if (vaziaFilaEnc(f)==FILAENC_VAZIA)
        return FILAENC_VAZIA;
    else
        memcpy(content,f->head->content, f->bytes);
    return removerFilaEncSemValor(f);
}

int removerFilaEncSemValor(tFilaEnc *f) {
    if (vaziaFilaEnc(f)==FILAENC_VAZIA)
        return FILAENC_VAZIA;
    tFilaIEnctem *aux = f->head;
    f->head=f->head->next;
    free(aux->content);
    free(aux);
    return FILAENC_OPERACAO_OK;
}

tFilaIEnctem* primeiroFilaEnc(tFilaEnc *f) {
    if (vaziaFilaEnc(f))
        return NULL;
    return ((tFilaIEnctem*)f->head);
}

int tamanhoFilaEnc(tFilaEnc * f){
    if(vaziaFilaEnc(f))
        return 0;
    unsigned int retorno=0;
    tFilaIEnctem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}
