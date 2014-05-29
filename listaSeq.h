/* 
 * File:   listaSeq.h
 * Author: Fábio Tramasoli (0619132)
 * About: Lista Seqüencial agnóstica a tipos.
 * 
 */

#define LISTASEQ_VAZIA -1
#define LISTASEQ_CHEIA 10
#define LISTASEQ_OPERACAO_OK 0
#define LISTASEQ_OPERACAO_ERR -2
#define LISTASEQ_TAMANHO 20

typedef struct{
    int inicio;
    int bytes;
    int tamanho;
    char *conteudo;
}tListaSeq;

void inicializaListaSeq(tListaSeq *f, int bytes);
int finalizaListaSeq(tListaSeq *f);
int vaziaListaSeq(tListaSeq *f);
int cheiaListaSeq(tListaSeq *f);
int inserirListaSeq(tListaSeq *f, int pos, void *valor);
int removerListaSeq(tListaSeq *f, int pos, void *valor);
int posicaoListaSeq(tListaSeq *f, void *valor);
int elementoListaSeq(tListaSeq *f, int pos, void *valor);
int tamanhoListaSeq(tListaSeq * f);