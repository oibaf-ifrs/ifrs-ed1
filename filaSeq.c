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
    return f->inicio == -1;
}

int cheiaFilaSeq(tFilaSeq *f) {
    return (((f->fim) + 1) % FILASEQ_TAMANHO) == (f->inicio);
}

int inserirFilaSeq(tFilaSeq *f, void *valor) {
    if (!cheiaFilaSeq(f)) {
        if (vaziaFilaSeq(f))f->inicio = 0;
        (f->fim)++;
        f->fim = (f->fim) % FILASEQ_TAMANHO;
        memcpy((f->conteudo+(f->fim*f->bytes)),valor,f->bytes);
        return FILASEQ_OPERACAO_OK;
    } else return FILASEQ_OPERACAO_ERR;
}

int removerFilaSeq(tFilaSeq *f, void *valor) {
    if (!vaziaFilaSeq(f)) {
        memcpy(valor,(f->conteudo+(f->inicio*f->bytes)),f->bytes);
        if (f->fim == f->inicio) {//condicao de 1 elemento
            inicializaFilaSeq(f,f->bytes);
        } else {//condicao >1 elemento
            (f->inicio)++;
        }
        return FILASEQ_OPERACAO_OK;
    } else {
        return FILASEQ_OPERACAO_ERR;
    }
}

int topoFilaSeq(tFilaSeq *f, void *valor) {
    if (!vaziaFilaSeq(f)) {
        memcpy(valor,(f->conteudo+(f->inicio*f->bytes)),f->bytes);
        return FILASEQ_OPERACAO_OK;
    } else {
        return FILASEQ_OPERACAO_ERR;
    }
}

int tamanhoFilaSeq(tFilaSeq * f){
    int cont=0;
    int aux=f->inicio;
    if(vaziaFilaSeq(f))return 0;
    while(aux!=f->fim){
        cont++;
        aux=(aux+1)%FILASEQ_TAMANHO;
    }
}