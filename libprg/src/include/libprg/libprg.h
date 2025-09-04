#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    int* elementos;
    int tamanho;
    int topo;
} pilha_t;

pilha_t* cria_pilha(int qnt);
void adiciona_elemento(pilha_t* pilha, double valor);
void remove_item(pilha_t* pilha);
void imprime_pilha(pilha_t* pilha);

#endif
