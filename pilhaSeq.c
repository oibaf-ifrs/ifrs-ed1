/* 
 * File:   pilhaSeq.c
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Seqüencial agnóstica a tipos.
 * 
 */

#include <string.h>
#include "pilhaSeq.h"

int inicializaPilhaSeq(tPilhaSeq *pilha){
        pilha->topo = -1;
        pilha->conteudo = malloc(sizeof(char));
}

int vaziaPilhaSeq (tPilhaSeq *pilha){
    return ((pilha->topo)==-1);
}

int  cheiaPilhaSeq (tPilhaSeq *pilha){
    return ((pilha->topo)==(PILHASEQ_TAMANHO-1));
}

int pushPilhaSeq(tPilhaSeq *pilha, void *valor, int bytes){
    if(cheiaPilhaSeq(pilha)==PILHASEQ_CHEIA){
        return PILHASEQ_CHEIA;
    } else{
        (pilha->topo)++;
        pilha->conteudo[pilha->topo] = malloc(bytes);
        memcpy(valor,pilha->conteudo[pilha->topo],bytes);
        return PILHASEQ_OPERACAO_OK;//indica sucesso
    }
}

int popPilhaSeq (tPilhaSeq *pilha, void *valor, int bytes){
    if(!vaziaPilhaSeq(pilha)){
        memcpy(pilha->conteudo[pilha->topo],valor,bytes);
        free(pilha->conteudo[pilha->topo]);
        (pilha->topo)--;
        return PILHASEQ_OPERACAO_OK;
    } else{
        return PILHASEQ_OPERACAO_ERR;
    }
}

int primeiroPilhaSeq (tPilhaSeq *pilha, void *valor, int bytes){
    if(!vaziaPilhaSeq(pilha)){
        memcpy(pilha->conteudo[pilha->topo],valor,bytes);
        return PILHASEQ_OPERACAO_OK;
    } else{
        return PILHASEQ_OPERACAO_ERR;
    }
}

int tamanhoPilhaSeq(tPilhaSeq *pilha){
    int status,bytes;
    char *aux;
    tPilhaSeq *pAux = malloc(sizeof(tPilhaSeq));
    inicializaPilhaSeq(&pAux);
    int cont=0;
    while(!vaziaPilhaSeq(pilha)){
        bytes=sizeof(pilha->conteudo[pilha->topo]);
        aux=malloc(bytes);
        status=popPilhaSeq(pilha,aux,bytes);
        if(status==PILHASEQ_OPERACAO_ERR){//algo ruim aconteceu
            printf("***Erro!***");
        }else{
            cont++;
            pushPilhaSeq(pAux,aux,bytes);
        }
        free(aux);
    }
    while(!vaziaPilhaSeq(pAux)){
        bytes=sizeof(pAux->conteudo[pAux->topo]);
        aux=malloc(bytes);
        popPilhaSeq(pAux,aux,bytes);
        pushPilhaSeq(pilha,aux,bytes);
        free(aux);
    }
    free(pAux);
    return cont;
}


