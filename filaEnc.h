/* 
 * File:   FilaEnc.h
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Encadeada agnóstica a tipos.
 * 
 */

#define FILAENC_VAZIA -1
#define FILAENC_CHEIA 10
#define FILAENC_OPERACAO_OK 0
#define FILAENC_OPERACAO_ERR 1

typedef struct{
    void *content;
    void *next;
    void *previous;
}tFilaIEnctem;

typedef struct{
    tFilaIEnctem *head;
    tFilaIEnctem *tail;
    int bytes;
}tFilaEnc;

int inicializaFilaEnc(tFilaEnc *,int);
int finalizaFilaEnc(tFilaEnc *);
int vaziaFilaEnc(tFilaEnc *);
int cheiaFilaEnc(tFilaEnc *);
int inserirFilaEnc(tFilaEnc *, void *);
int removerFilaEnc(tFilaEnc *,void*);
int removerFilaEncSemValor(tFilaEnc *);
tFilaIEnctem* primeiroFilaEnc(tFilaEnc *);
int tamanhoFilaEnc(tFilaEnc *);
