/* 
 * File:   ListaEnc.c
 * Author: Fábio Tramasoli (0619132)
 * About: Lista Encadeada agnóstica a tipos.
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
    while(removerListaEnc(f,1,aux)==LISTAENC_OPERACAO_OK) {
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
    if(f!=NULL && pos>0) {
        tListaEncItem *newVal = malloc(sizeof(tListaEncItem));
        newVal->content = malloc(f->bytes);
        memcpy(newVal->content, valor, f->bytes);
        newVal->next=newVal->previous=NULL;
        if(vaziaListaEnc(f))
            f->head=f->tail=newVal;
        else {
            int count;
            tListaEncItem *aux=f->head,*tmp;
            for (count=0;count<pos||aux==NULL;count++)
                aux=aux->next;
            tmp=aux->next;
            aux->next=newVal;
            if(count==tamanhoListaEnc(f))
                f->tail=newVal;
            else
                newVal->next=tmp;
            if(count==0)
                f->head=newVal;
            else
                newVal->previous=aux;
        }
        return LISTAENC_OPERACAO_OK;
    }
    return LISTAENC_OPERACAO_ERR;
}

int removerListaEnc(tListaEnc *f, int pos, void *content) {
    if (vaziaListaEnc(f)==LISTAENC_VAZIA)
        return LISTAENC_VAZIA;
    else
        memcpy(content,f->head->content, f->bytes);
    //return removerListaEncSemValor(f);
    return 1;
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
    tListaEncItem *go;
    for(go=f->head;go!=NULL;go=go->next)
        retorno++;
    return retorno;
}
