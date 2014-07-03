/* 
 * File:   ListaEnc.c
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "listaEnc.h"

int inicializaListaEnc(tListaEnc *f, int bytes) {
    if(f!=NULL) {
        f->head=f->tail=NULL;
        f->bytes=bytes;
        return LISTAENC_OPERACAO_OK;
        f->size=0;
    }
    return LISTAENC_OPERACAO_ERR;
}

int finalizaListaEnc(tListaEnc *f) {
    char *aux = malloc(f->bytes);
    while(removerListaEnc(f,aux)==LISTAENC_OPERACAO_OK) {
    }
    free(aux);
    return LISTAENC_OPERACAO_OK;
}

int vaziaListaEnc(tListaEnc *f) {
    if (f->head==NULL)
        return LISTAENC_VAZIA;
    else
        return LISTAENC_OPERACAO_OK;
}

int cheiaListaEnc(tListaEnc *f) {
    return LISTAENC_OPERACAO_OK;
}

int inserirListaEnc(tListaEnc *f, int pos, void *valor) {
    //TODO: implementar
    tFilaIEnctem *newVal = malloc(sizeof(tFilaIEnctem));
    newVal->content = malloc(f->bytes);
    memcpy(newVal->content, valor, f->bytes);
    newVal->next=NULL;
    if(vaziaListaEnc(f))
        f->head=f->tail=newVal;
    else 
        f->tail->next=f->tail=newVal;
    return LISTAENC_OPERACAO_OK;
}

int removerListaEnc(tListaEnc *f, int pos, void *content) {
    //TODO: implementar
    if (vaziaListaEnc(f)==LISTAENC_VAZIA)
        return LISTAENC_VAZIA;
    else
        memcpy(content,f->head->content, f->bytes);
    return removerListaEncSemValor(f);
}

int posicaoListaEnc(tListaEnc *f, void *valor) {
    //TODO: implementar
}

int elementoListaEnc(tListaEnc *f, int pos, void *valor) {
    //TODO: implementar
}

int tamanhoListaEnc(tListaEnc * f){
    if(vaziaListaEnc(f))
        return 0;
    unsigned int retorno=0;
    tFilaIEnctem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}
