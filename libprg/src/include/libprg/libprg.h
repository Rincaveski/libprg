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
void listar_primeiro_elemento_e_tamanho(lista_t* lista);
void listar(lista_t* lista);

// Lista encadeada
typedef struct no no_t;
no_t* criar_no(int valor);
no_t* criar_no_encadeado(int valor);
void adicionar_no(no_t** inicio, int valor);
void adicionar_no_circular(no_t** inicio, int valor);
no_t *buscar_no(no_t** inicio, int valor);
void remover_no(no_t** inicio, int valor);
void destruir_no(no_t** inicio);
void destruir_no_circular(no_t** inicio);
void mostrar_no(no_t** inicio);
no_t* mostrar_inicio_no(no_t** inicio);

#endif