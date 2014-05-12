/* 
 * File:   pilhaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Encadeada agnóstica a tipos.
 * 
 */

#define PILHAENC_VAZIA -1
#define PILHAENC_CHEIA 10
#define PILHAENC_OPERACAO_OK 0
#define PILHAENC_OPERACAO_ERR 1

typedef struct{
    void *content;
    void *next;
    void *previous;
}tPilhaEncItem;

typedef struct{
    tPilhaEncItem *head;
    tPilhaEncItem *tail;
    int bytes;
}tPilhaEnc;

int inicializaPilhaEnc(tPilhaEnc *f,int);
int vaziaPilhaEnc(tPilhaEnc *f);
int cheiaPilhaEnc(tPilhaEnc *f);
int pushPilhaEnc(tPilhaEnc *f, void*);
int popPilhaEnc(tPilhaEnc *f, void*);
tPilhaEncItem* primeiroPilhaEnc(tPilhaEnc *f);
int tamanhoPilhaEnc(tPilhaEnc * f);
int finalizaPilhaEnc(tPilhaEnc * f);
