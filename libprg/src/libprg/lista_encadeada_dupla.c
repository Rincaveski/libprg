#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_duplo {
    int valor;
    struct no_duplo *anterior;
    struct no_duplo *proximo;
} no_duplo_t;

no_duplo_t* criar_no_duplo(int valor) {
    no_duplo_t* no_duplo = malloc(sizeof(no_t));
    no_duplo->valor = valor;
    no_duplo->proximo = NULL;
    no_duplo->anterior = NULL;

    return no_duplo;
}

void adicionar_no_duplo(no_duplo_t** inicio, int valor) {
    no_duplo_t* novo_no_duplo = criar_no_duplo(valor);
    novo_no_duplo->proximo = *inicio;
    (*inicio)->anterior = novo_no_duplo;
    novo_no_duplo->anterior = NULL;
    *inicio = novo_no_duplo;
}

no_duplo_t* buscar_no_duplo(no_t** inicio, int valor) {
    no_duplo_t* atual = *inicio;

    while (atual)
    {
        if (atual->valor == valor)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void remover_no_duplo(no_duplo_t** inicio, int valor) {
    no_duplo_t* atual = *inicio;

    while (atual) {
        if (atual->valor == valor) {
            if (atual->proximo) {
                atual->proximo->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            } else {
                atual = atual->proximo;
                atual->anterior = NULL;
            }
            free(atual);
            break;
        }

        atual = atual->proximo;
    }
}

void destruir_no_duplo(no_t** inicio) {

}