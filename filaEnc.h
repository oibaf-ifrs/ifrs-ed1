/* 
 * File:   FilaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#define FILASEQ_VAZIA -1
#define FILASEQ_CHEIA 10
#define FILASEQ_OPERACAO_OK 0
#define FILASEQ_OPERACAO_ERR 1

typedef struct{
    void *content;
    void *next;
    void *previous;
}tFilaIEnctem;

typedef struct{
    tFilaIEnctem *head;
    tFilaIEnctem *tail;
}tFilaEnc;

int inicializaFilaEnc(tFilaEnc *);
int finalizaFilaEnc(tFilaEnc *);
int vaziaFilaEnc(tFilaEnc *);
int cheiaFilaEnc(tFilaEnc *);
int inserirFilaEnc(tFilaEnc *, void *, int);
int removerFilaEncComValor(tFilaEnc *,void*,int);
int removerFilaEnc(tFilaEnc *);
tFilaIEnctem* primeiroFilaEnc(tFilaEnc *);
int tamanhoFilaEnc(tFilaEnc *);
