/* 
 * File:   pilhaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Pilha Encadeada agnóstica a tipos.
 * 
 */

#define PILHA_VAZIA -1
#define PILHA_CHEIA 10
#define PILHA_OPERACAO_OK 0
#define PILHA_OPERACAO_ERR 1

typedef struct{
    void *content;
    void *next;
    void *previous;
}tPilhaItem;

typedef struct{
    tPilhaItem *head;
    tPilhaItem *tail;
}tPilha;

int inicializaPilha(tPilha *f);
int vaziaPilha(tPilha *f);
int cheiaPilha(tPilha *f);
int pushPilha(tPilha *f, void*, int);
int popPilha(tPilha *f, void*, int);
tPilhaItem* primeiroPilha(tPilha *f);
int tamanhoPilha(tPilha * f);
