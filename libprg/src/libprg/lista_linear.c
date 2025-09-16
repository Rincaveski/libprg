#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
} lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade) {
    lista_linear_t* lista = malloc(sizeof(lista));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void inserir_lista_linear(lista_linear_t* lista, int valor) {
    if (cheia(lista)) {
        exit(EXIT_FAILURE);
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

int buscar_lista_linear(lista_linear_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }

    return -1;
}

void remover_item_lista_linear(lista_linear_t* lista, int valor) {
    int indice = buscar_lista_linear(lista, valor);

    if (indice == -1) {
        exit(EXIT_FAILURE);
    }

    lista->elementos[indice] = lista->elementos[lista->tamanho];
    lista->tamanho--;
}

bool vazia(lista_linear_t* lista) {
    return lista->tamanho == 0;
}

bool cheia(lista_linear_t* lista) {
    return lista->tamanho >= lista->capacidade;
}

void destruir(lista_linear_t* lista) {
    free(lista->elementos);
    free(lista);
}