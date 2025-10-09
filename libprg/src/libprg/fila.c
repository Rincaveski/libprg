#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
} fila_t;

static bool cheia(fila_t* fila);

fila_t* criar_fila(int capacidade) {
    fila_t* fila = malloc(sizeof(fila_t));
    fila->elementos = malloc(sizeof(int) * capacidade);
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
};
void enfileirar(fila_t* fila, int valor) {
    if (cheia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
};

void desenfileirar(fila_t* fila) {
    if (fila->tamanho <= 0) {
        exit(EXIT_FAILURE);
    }

    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
}

int inicio_fila(fila_t* fila) {
    return fila->elementos[fila->inicio];
}

int fim_fila(fila_t* fila) {
    if (fila->tamanho > 0 &&
        (fila->inicio == fila->fim) &&
        fila->fim == 0) {
        return fila->elementos[fila->capacidade - 1];
    }
    return fila->elementos[fila->fim];
}

int tamanho_fila(fila_t* fila) {
    return fila->tamanho;
}

void imprime_fila(fila_t* fila) {
    for (int i = 0; i < fila->tamanho; i++) {
        int indice = (fila->inicio + i) % fila->capacidade;
        printf("%d ", fila->elementos[indice]);
    }
    printf("\n");
}

void destruir_fila(fila_t* fila) {
    free(fila->elementos);
    free(fila);
}

static bool cheia(fila_t* fila) {
    return fila->tamanho >= fila->capacidade;
}