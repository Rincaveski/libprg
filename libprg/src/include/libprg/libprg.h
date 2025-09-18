#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

// Pilha
typedef struct pilha pilha_t;
pilha_t* cria_pilha(int qnt);
void empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
void imprime_pilha(pilha_t* pilha);
void destruir_pilha(pilha_t* pilha);
int topo_pilha(pilha_t* pilha);
int tamanho_pilha(pilha_t* pilha);

// Fila
typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
void desenfileirar(fila_t* fila);
int inicio_fila(fila_t* fila);
int fim_fila(fila_t* fila);
int tamanho_fila(fila_t* fila);
void imprime_fila(fila_t* fila);
void destruir_fila(fila_t* fila);


// Lista
typedef struct lista lista_t;
lista_t* criar_lista(int capacidade, bool ordenar);
void inserir_lista(lista_t* lista, int valor);
int buscar_lista(lista_t* lista, int valor);
void remover_item_lista(lista_t* lista, int valor);
void destruir_lista(lista_t* lista);

#endif