/* 
 * File:   FilaSeq.h
 * Author: Fábio Tramasoli (0619132)
 * About: Fila Seqüencial agnóstica a tipos.
 * 
 */

#define FILASEQ_VAZIA -1
#define FILASEQ_CHEIA 10
#define FILASEQ_OPERACAO_OK 0
#define FILASEQ_OPERACAO_ERR 1
#define FILASEQ_TAMANHO 10

typedef struct{
    int inicio;
    int fim;
    int bytes;
    char *conteudo;
}tFilaSeq;

void inicializaFilaSeq(tFilaSeq *f, int bytes);
int finalizaFilaSeq(tFilaSeq *f);
int vaziaFilaSeq(tFilaSeq *f);
int cheiaFilaSeq(tFilaSeq *f);
int inserirFilaSeq(tFilaSeq *f, void *valor);
int removerFilaSeq(tFilaSeq *f, void *valor);
int topoFilaSeq(tFilaSeq *f, void *valor);
int tamanhoFilaSeq(tFilaSeq * f);
