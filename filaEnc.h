/* 
 * File:   FilaSeq.h
 * Author: FABIO
 *
 * Created on 4 de Junho de 2013, 10:22
 */

#include "tipos.h"


typedef struct{
    abstractContent content;
    void *next;
}tFilaItem;

typedef struct{
    tFilaItem *head;
    tFilaItem *tail;
}tFila;

void inicializaFila(tFila *f);
int vaziaFila(tFila *f);
int cheiaFila(tFila *f);
int inserirFila(tFila *f, abstractContent valor);
abstractContent removerFila(tFila *f);
tFilaItem* primeiroFila(tFila *f);
int tamanhoFila(tFila * f);
