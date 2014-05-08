/* 
 * File:   pilhaSeq.h
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Seqüencial agnóstica a tipos.
 * 
 */

#define PILHASEQ_VAZIA -1
#define PILHASEQ_CHEIA 10
#define PILHASEQ_OPERACAO_OK 0
#define PILHASEQ_OPERACAO_ERR 1
#define PILHASEQ_TAMANHO 10

typedef struct{
    char **conteudo;
    int topo;
    int bytes;
}tPilhaSeq;

int inicializaPilhaSeq(tPilhaSeq *, int bytes);
int vaziaPilhaSeq (tPilhaSeq *);
int cheiaPilhaSeq (tPilhaSeq *);
int pushPilhaSeq(tPilhaSeq *, void *);
int popPilhaSeq (tPilhaSeq *, void *);
int primeiroPilhaSeq (tPilhaSeq *, void *);
int tamanhoPilhaSeq(tPilhaSeq *);
