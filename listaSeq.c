/* 
 * File:   ListaSeq.c
 * Author: Fábio Tramasoli (0619132)
 * About: Lista Seqüencial agnóstica a tipos.
 * 
 */

#include <string.h>
#include "listaSeq.h"

void inicializaListaSeq(tListaSeq *f, int bytes) {
    f->inicio = -1;
    f->bytes= bytes;
    f->conteudo = malloc(sizeof(char)*LISTASEQ_TAMANHO*f->bytes);
}

int finalizaListaSeq(tListaSeq *f) {
    free(f->conteudo);
    return LISTASEQ_OPERACAO_OK;
}

int vaziaListaSeq(tListaSeq *f) {
    return ((f->tamanho==0)?LISTASEQ_VAZIA:LISTASEQ_OPERACAO_OK);
}

int cheiaListaSeq(tListaSeq *f) {
    return ((f->tamanho==LISTASEQ_TAMANHO)?LISTASEQ_CHEIA:LISTASEQ_OPERACAO_OK);
}

int inserirListaSeq(tListaSeq *f, int pos, void *valor) {
    if (cheiaListaSeq(f)!=LISTASEQ_CHEIA) {
        if (vaziaListaSeq(f)==LISTASEQ_VAZIA)
            f->inicio = 0;
        else {
            int count;
            for(count=f->tamanho;count>pos-1;count--) {
                memcpy((f->conteudo+((count)*f->bytes)),(f->conteudo+((count-1)*f->bytes)),f->bytes);
            }
        }
        f->tamanho++;
        memcpy((f->conteudo+((pos-1)*f->bytes)),valor,f->bytes);
        return LISTASEQ_OPERACAO_OK;
    } else return LISTASEQ_OPERACAO_ERR;
}

int removerListaSeq(tListaSeq *f, int pos, void *valor) {
    if (vaziaListaSeq(f)!=LISTASEQ_VAZIA && pos>f->inicio && pos<=f->tamanho) {
        memcpy(valor,(f->conteudo+(pos-1*f->bytes)),f->bytes);
        f->tamanho--;
        int count;
        for(count=pos-1;count<f->tamanho;count++) {
            memcpy((f->conteudo+(count*f->bytes)),(f->conteudo+((count+1)*f->bytes)),f->bytes);
        }
        if (vaziaListaSeq(f)==LISTASEQ_VAZIA) {
            inicializaFilaSeq(f,f->bytes);
        }
        return LISTASEQ_OPERACAO_OK;
    } else {
        return LISTASEQ_OPERACAO_ERR;
    }
}

int posicaoListaSeq(tListaSeq *f, void *valor)  {
    int count, retorno=LISTASEQ_OPERACAO_ERR;
    for(count=0;count<f->tamanho;count++)
        if (memcmp(valor,(f->conteudo+(count*f->bytes)),f->bytes)==0) {
            retorno=count+1;
            count=f->tamanho;
        }
    return retorno;
}

int elementoListaSeq(tListaSeq *f, int pos, void *valor) {
    if(pos>f->inicio && pos<=f->tamanho) {
        memcpy(valor,f->conteudo+((pos-1)*f->bytes),f->bytes);
        return LISTASEQ_OPERACAO_OK;
    }
        return LISTASEQ_OPERACAO_ERR;
}

int tamanhoListaSeq(tListaSeq * f) {
    return f->tamanho;
}