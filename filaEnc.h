/* 
 * File:   FilaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#define FILA_VAZIA -1
#define FILA_CHEIA 10
#define FILA_OPERACAO_OK 0
#define FILA_OPERACAO_ERR 1

typedef struct{
    void *content;
    void *next;
    void *previous;
}tFilaItem;

typedef struct{
    tFilaItem *head;
    tFilaItem *tail;
}tFilaEnc;

int inicializaFila(tFilaEnc *);
int vaziaFila(tFilaEnc *);
int cheiaFila(tFilaEnc *);
int inserirFila(tFilaEnc *, void *, int);
int removerFilaComValor(tFilaEnc *,void*,int);
int removerFila(tFilaEnc *);
tFilaItem* primeiroFila(tFilaEnc *);
int tamanhoFila(tFilaEnc *);
