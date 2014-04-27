/* 
 * File:   FilaEnc.c
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "filaEnc.h"

int inicializaFila(tFilaEnc *f) {
    if(f!=NULL) {
        f->head=f->tail=NULL;
        return FILA_OPERACAO_OK;
    }
    return FILA_OPERACAO_ERR;
}

int vaziaFila(tFilaEnc *f) {
    return (f->head==NULL);
}

int cheiaFila(tFilaEnc *f) {
    return 0;
}

int inserirFila(tFilaEnc *f, void *valor, int bytes) {
    tFilaItem *newVal = malloc(sizeof(tFilaItem));
    newVal->content = malloc(bytes);
    memcpy(newVal->content, valor, bytes);
    newVal->next=NULL;
    if(vaziaFila(f))
        f->head=f->tail=newVal;
    else 
        f->tail->next=f->tail=newVal;
    return FILA_OPERACAO_OK;
}

int removerFilaComValor(tFilaEnc *f, void *content, int bytes) {
    memcpy(content,f->head->content, bytes);
    return removerFila(f);
}

int removerFila(tFilaEnc *f) {
    if (vaziaFila(f))
        return FILA_VAZIA;
    tFilaItem *aux = f->head;
    f->head=f->head->next;
    free(aux);
    return FILA_OPERACAO_OK;
}

tFilaItem* primeiroFila(tFilaEnc *f) {
    if (vaziaFila(f))
        return NULL;
    return ((tFilaItem*)f->head);
}

int tamanhoFila(tFilaEnc * f){
    if(vaziaFila(f))
        return 0;
    unsigned int retorno=0;
    tFilaItem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}
