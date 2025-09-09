#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

// Pilha
typedef struct pilha pilha_t;
pilha_t* cria_pilha(int qnt);
void empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
void imprime_pilha(pilha_t* pilha);
void destruir(pilha_t* pilha);
int topo(pilha_t* pilha);
int tamanho(pilha_t* pilha);

// Fila
typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
bool cheia(fila_t* fila);

#endif
