/* 
 * File:   FilaSeq.c
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Seqüencial agnóstica a tipos.
 * 
 */

#include <string.h>
#include "filaSeq.h"

void inicializaFilaSeq(tFilaSeq *f, int bytes) {
    f->fim = -1;
    f->inicio = -1;
    f->bytes= bytes;
    f->conteudo = malloc(sizeof(char)*FILASEQ_TAMANHO*f->bytes);
}

int finalizaFilaSeq(tFilaSeq *f) {
    free(f->conteudo);
    return FILASEQ_OPERACAO_OK;
}

int vaziaFilaSeq(tFilaSeq *f) {
    if (f->inicio == -1)
        return FILASEQ_VAZIA;
    else
        return FILASEQ_OPERACAO_OK;
}

int cheiaFilaSeq(tFilaSeq *f) {
    if ( (((f->fim) + 1) % FILASEQ_TAMANHO) == (f->inicio) )
        return FILASEQ_CHEIA;
    else
        return FILASEQ_OPERACAO_OK;
}

int inserirFilaSeq(tFilaSeq *f, void *valor) {
    if (cheiaFilaSeq(f)!=FILASEQ_CHEIA) {
        if (vaziaFilaSeq(f)==FILASEQ_VAZIA)f->inicio = 0;
        (f->fim)++;
        f->fim = (f->fim) % FILASEQ_TAMANHO;
        memcpy((f->conteudo+(f->fim*f->bytes)),valor,f->bytes);
        return FILASEQ_OPERACAO_OK;
    } else return FILASEQ_OPERACAO_ERR;
}

int removerFilaSeq(tFilaSeq *f, void *valor) {
    if (vaziaFilaSeq(f)!=FILASEQ_VAZIA) {
        memcpy(valor,(f->conteudo+(f->inicio*f->bytes)),f->bytes);
        if (f->fim == f->inicio) {
            inicializaFilaSeq(f,f->bytes);
        } else {
            (f->inicio)++;
        }
        return FILASEQ_OPERACAO_OK;
    } else {
        return FILASEQ_OPERACAO_ERR;
    }
}

int topoFilaSeq(tFilaSeq *f, void *valor) {
    if (vaziaFilaSeq(f)!=FILASEQ_VAZIA) {
        memcpy(valor,(f->conteudo+(f->inicio*f->bytes)),f->bytes);
        return FILASEQ_OPERACAO_OK;
    } else {
        return FILASEQ_OPERACAO_ERR;
    }
}

int tamanhoFilaSeq(tFilaSeq * f){
    int cont=0;
    int aux=f->inicio;
    if(vaziaFilaSeq(f)==FILASEQ_VAZIA)return 0;
    while(aux!=f->fim){
        cont++;
        aux=(aux+1)%FILASEQ_TAMANHO;
    }
}