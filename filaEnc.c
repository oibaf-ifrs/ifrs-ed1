/* 
 * File:   FilaEnc.c
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "filaEnc.h"

int inicializaFilaEnc(tFilaEnc *f) {
    if(f!=NULL) {
        f->head=f->tail=NULL;
        return FILASEQ_OPERACAO_OK;
    }
    return FILASEQ_OPERACAO_ERR;
}

int finalizaFilaEnc(tFilaEnc *f) {
    return FILASEQ_OPERACAO_OK;
}

int vaziaFilaEnc(tFilaEnc *f) {
    return (f->head==NULL);
}

int cheiaFilaEnc(tFilaEnc *f) {
    return 0;
}

int inserirFilaEnc(tFilaEnc *f, void *valor, int bytes) {
    tFilaIEnctem *newVal = malloc(sizeof(tFilaIEnctem));
    newVal->content = malloc(bytes);
    memcpy(newVal->content, valor, bytes);
    newVal->next=NULL;
    if(vaziaFilaEnc(f))
        f->head=f->tail=newVal;
    else 
        f->tail->next=f->tail=newVal;
    return FILASEQ_OPERACAO_OK;
}

int removerFilaEncComValor(tFilaEnc *f, void *content, int bytes) {
    memcpy(content,f->head->content, bytes);
    return removerFilaEnc(f);
}

int removerFilaEnc(tFilaEnc *f) {
    if (vaziaFilaEnc(f))
        return FILASEQ_VAZIA;
    tFilaIEnctem *aux = f->head;
    f->head=f->head->next;
    free(aux->content);
    free(aux);
    return FILASEQ_OPERACAO_OK;
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
