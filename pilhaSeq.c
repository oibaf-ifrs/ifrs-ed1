/* 
 * File:   pilhaSeq.c
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Seqüencial agnóstica a tipos.
 * 
 */

#include <string.h>
#include "pilhaSeq.h"

int inicializaPilhaSeq(tPilhaSeq *pilha, int bytes){
        pilha->topo = -1;
        pilha->bytes=bytes;
        pilha->conteudo = malloc(sizeof(char)*PILHASEQ_TAMANHO*pilha->bytes);
}

int vaziaPilhaSeq (tPilhaSeq *pilha){
    if ((pilha->topo)==-1)
        return PILHASEQ_VAZIA;
    else
        return PILHASEQ_OPERACAO_OK;
}

int  cheiaPilhaSeq (tPilhaSeq *pilha){
    if ((pilha->topo)==(PILHASEQ_TAMANHO-1))
        return PILHASEQ_CHEIA;
    return PILHASEQ_OPERACAO_OK;
    //corrigir para retornar pilhaseq_cheia
}

int pushPilhaSeq(tPilhaSeq *pilha, void *valor){
    if(cheiaPilhaSeq(pilha)==PILHASEQ_CHEIA){
        return PILHASEQ_CHEIA;
    } else{
        (pilha->topo)++;
        memcpy((pilha->conteudo+(pilha->topo*pilha->bytes)),valor,pilha->bytes);
        return PILHASEQ_OPERACAO_OK;//indica sucesso
    }
}

int popPilhaSeq (tPilhaSeq *pilha, void *valor){
    if(vaziaPilhaSeq(pilha)!=PILHASEQ_VAZIA){
        memcpy(valor,(pilha->conteudo+(pilha->topo*pilha->bytes)),pilha->bytes);
        (pilha->topo)--;
        return PILHASEQ_OPERACAO_OK;
    } else{
        return PILHASEQ_OPERACAO_ERR;
    }
}

int primeiroPilhaSeq (tPilhaSeq *pilha, void *valor){
    if(vaziaPilhaSeq(pilha)!=PILHASEQ_VAZIA){
        memcpy(valor,pilha->conteudo[pilha->topo],pilha->bytes);
        return PILHASEQ_OPERACAO_OK;
    } else{
        return PILHASEQ_OPERACAO_ERR;
    }
}

int tamanhoPilhaSeq(tPilhaSeq *pilha){
    int status;
    char *aux;
    tPilhaSeq *pAux = malloc(sizeof(tPilhaSeq));
    inicializaPilhaSeq(&pAux,pilha->bytes);
    int cont=0;
    while(!vaziaPilhaSeq(pilha)){
        aux=malloc(pilha->bytes);
        status=popPilhaSeq(pilha,aux);
        if(status==PILHASEQ_OPERACAO_ERR){//algo ruim aconteceu
            printf("***Erro!***");
        }else{
            cont++;
            pushPilhaSeq(pAux,aux);
        }
        free(aux);
    }
    while(!vaziaPilhaSeq(pAux)){
        aux=malloc(pilha->bytes);
        popPilhaSeq(pAux,aux);
        pushPilhaSeq(pilha,aux);
        free(aux);
    }
    free(pAux);
    return cont;
}


