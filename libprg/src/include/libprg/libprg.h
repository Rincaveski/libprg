#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

// Pilha
typedef struct pilha pilha_t;
pilha_t* cria_pilha(int qnt);
void empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
void imprime_pilha(pilha_t* pilha);
void imprime_pilha_hanoi(pilha_t* esquerda, pilha_t* meio, pilha_t* direita, int n);
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
int tamanho_lista(lista_t* lista);
bool lista_cheia(lista_t* lista);
int buscar_na_posicao(lista_t* lista, int posicao);

// Lista encadeada
typedef struct no no_binario_t;
no_binario_t* criar_no(int valor);
no_binario_t* criar_no_encadeado(int valor);
void adicionar_no(no_binario_t** inicio, int valor);
void adicionar_no_circular(no_binario_t** inicio, int valor);
no_binario_t *buscar_no(no_binario_t** inicio, int valor);
void remover_no(no_binario_t** inicio, int valor);
void destruir_arvore(no_binario_t** inicio);
void destruir_no_circular(no_binario_t** inicio);
void mostrar_no(no_binario_t** inicio);
no_binario_t* mostrar_inicio_no(no_binario_t** inicio);

// Lista encadeada dupla
typedef struct no_duplo no_duplo_t;
no_duplo_t* criar_no_duplo(int valor);
void adicionar_no_duplo(no_duplo_t** inicio, int valor);
no_duplo_t* buscar_no_duplo(no_binario_t** inicio, int valor);
void remover_no_duplo(no_duplo_t** inicio, int valor);
void destruir_no_duplo(no_binario_t** inicio);

// Arvore binaria
typedef struct arvore_binaria arvore_binaria_t;
arvore_binaria_t* criar_no(int valor);
void destruir_arvore(arvore_binaria_t *no);
arvore_binaria_t* inserir_folha(arvore_binaria_t* raiz, int valor);
bool busca_valor_arvore(arvore_binaria_t* raiz, int valor);
arvore_binaria_t* remover_valor_arvore(arvore_binaria_t* raiz, int valor);
arvore_binaria_t* encontrar_no_minimo_arvore(arvore_binaria_t* raiz);
int maior_valor_arvore(arvore_binaria_t* raiz);
int menor_valor_arvore(arvore_binaria_t* raiz);
int altura_arvore(arvore_binaria_t* raiz);
int tamanho_arvore(arvore_binaria_t* raiz);
void imprimir_arvore_em_ordem(arvore_binaria_t* raiz);
void imprimir_arvore_em_pre_ordem(arvore_binaria_t* raiz);
void imprimir_arvore_em_pos_ordem(arvore_binaria_t* raiz);
void imprimir_arvore_por_largura(arvore_binaria_t* raiz);

// Ordenacao
void bubble_sort(int* vetor, int tamanho);
void insertion_sort(int* vetor, int tamanho);
void selection_sort(int* vetor, int tamanho);
void merge(int* vetor, int esquerda, int meio, int direita);
void merge_sort(int* vetor, int esquerda, int direita);
int particiona(int* vetor, int esquerda, int direita);
void quick_sort(int* vetor, int esquerda, int direita);

// Dicionario
typedef struct pessoa pessoa_t;
typedef struct no no_dicionario_t;
typedef struct dicionario dicionario_t;
dicionario_t *criar_dicionario(int m);
int hash(const char *chave, int m);
void destruir_pessoa(pessoa_t *pessoa);
void destruir_no(no_dicionario_t *no);
void destruir_dicionario(dicionario_t *d;
bool inserir(dicionario_t *d, char *chave, pessoa_t *valor);
pessoa_t *buscar(dicionario_t *d, char *chave);
void imprimir_pessoa(dicionario_t *d, char *chave);

#endif
