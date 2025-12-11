#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct no {
    int valor;
    no_binario_t* proximo;
} no_binario_t;

no_binario_t* criar_no(int valor) {
    no_binario_t* no = malloc(sizeof(no_binario_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

no_binario_t* criar_no_encadeado(int valor) {
    no_binario_t *no = malloc(sizeof(no_binario_t));
    no->valor = valor;
    no->proximo = no;

    return no;
}

void adicionar_no(no_binario_t** inicio, int valor) {
    no_binario_t* no = criar_no(valor);
    no->proximo = *inicio;
    *inicio = no;
}

void adicionar_no_circular(no_binario_t** inicio, int valor) {
    no_binario_t* novo_no = criar_no_encadeado(valor);
    novo_no->proximo = *inicio;

    no_binario_t* ultimo = *inicio;

    while (ultimo->proximo != *inicio) {
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = novo_no;
    *inicio = novo_no;
}

no_binario_t *buscar_no(no_binario_t** inicio, int valor) {
    no_binario_t *atual = *inicio;

    while (atual) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

void remover_no(no_binario_t** inicio, int valor) {
    no_binario_t *atual = *inicio;
    no_binario_t *anterior = NULL;

    while (atual) {
        if (atual->valor == valor) {
            anterior->proximo = atual->proximo;
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                *inicio = atual->proximo;
            }
            free(atual);
            break;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void destruir_arvore(no_binario_t** inicio) {
    no_binario_t* atual = *inicio;

    while (atual) {
        no_binario_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void destruir_no_circular(no_binario_t** inicio) {
    no_binario_t* atual = *inicio;

    while (atual) {
        no_binario_t* proximo = atual->proximo;
        free(atual);
        if (proximo == *inicio) {
            break;
        }
        atual = proximo;
    }
}

void mostrar_no(no_binario_t** inicio) {
    no_binario_t* atual = *inicio;

    while (atual)
    {
        no_binario_t* proximo = atual->proximo;
        printf(" %d", atual->valor);
        atual = proximo;
    }
}

no_binario_t* mostrar_inicio_no(no_binario_t** inicio) {
    if (inicio)
    {
        return *inicio;
    }
    return NULL;
}