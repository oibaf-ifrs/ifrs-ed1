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
    void *previous;
}tPilhaItem;

typedef struct{
    tPilhaItem *head;
    tPilhaItem *tail;
}tPilha;

void inicializaPilha(tPilha *f);
int vaziaPilha(tPilha *f);
int cheiaPilha(tPilha *f);
int pushPilha(tPilha *f, abstractContent valor);
abstractContent popPilha(tPilha *f);
tPilhaItem* primeiroPilha(tPilha *f);
int tamanhoPilha(tPilha * f);
