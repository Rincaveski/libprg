#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct lista {
    int* elementos;
    int tamanho;
    int capacidade;
    bool isOrdenada;
} lista_t;

bool vazia(lista_t* lista);
static bool cheia(lista_t* lista);
void inserir_nao_ordenada(lista_t *lista, int valor);
void inserir_ordenada(lista_t *lista, int valor);
int busca_linear(lista_t* lista, int valor);
int busca_binaria(lista_t* lista, int valor);

lista_t* criar_lista(int capacidade, bool ordenar) {
    lista_t* lista = malloc(sizeof(lista));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->isOrdenada = ordenar;

    return  lista;
}

void inserir_lista(lista_t* lista, int valor) {
    if (cheia(lista)) {
        exit(EXIT_FAILURE);
    }

    if (lista->isOrdenada) {
        inserir_ordenada(lista, valor);
    } else {
        inserir_nao_ordenada(lista, valor);
    }
}

int buscar_lista(lista_t* lista, int valor) {
    if (lista->isOrdenada) {
        return busca_binaria(lista, valor);
    }

    return busca_linear(lista, valor);
}

void remover_item_lista(lista_t* lista, int valor) {
    int indice = buscar_lista(lista, valor);

    if (indice == -1) {
        exit(EXIT_FAILURE);
    }

    // listar(lista);

    lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
    lista->tamanho--;

    // listar(lista);
}

void destruir_lista(lista_t* lista) {
    free(lista->elementos);
    free(lista);
}

void listar_primeiro_elemento_e_tamanho(lista_t* lista) {
    printf("Primeiro elemento: %d\nTamanho da lista: %d\n", lista->elementos[0], lista->tamanho);
}

void listar(lista_t* lista) {
    for (int i = 0; i < lista->tamanho; ++i) {
        printf("Item %d: %d\n", (i + 1), lista->elementos[i]);
    }
}

//-------------------------------------------//

bool vazia(lista_t* lista) {
    return lista->tamanho == 0;
}

static bool cheia(lista_t* lista) {
    return lista->tamanho >= lista->capacidade;
}

void inserir_nao_ordenada(lista_t *lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

void inserir_ordenada(lista_t *lista, int valor) {
    for (int i = lista->tamanho - 1; i < 0; --i) {
        if (lista->elementos[i] < valor) {
            lista->elementos[i + 1] = valor;
            lista->tamanho++;
            break;
        }

        lista->elementos[i + 1] = lista->elementos[i];
    }
}

int busca_binaria(lista_t* lista, int valor) {
    int indice = lista->tamanho / 2;


    // while () {
    //     if (lista->elementos[indice] == valor) {
    //         return indice;
    //     }
    //
    //     if (lista->elementos[indice] < valor) {
    //         indice = lista->tamanho
    //     }
    // }
}

int busca_linear(lista_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }

    return -1;
}