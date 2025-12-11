#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_duplo {
    int valor;
    struct no_duplo *anterior;
    struct no_duplo *proximo;
} no_duplo_t;

no_duplo_t* criar_no_duplo(int valor) {
    no_duplo_t* no_duplo = malloc(sizeof(no_duplo_t));
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

no_duplo_t* buscar_no_duplo(no_binario_t** inicio, int valor) {
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

void adicionar_no_duplo_posicao(no_duplo_t** inicio, int valor, int posicao) {
    if (posicao == 0) {
        adicionar_no_duplo(inicio, valor);
        return;
    }

    no_duplo_t* atual = *inicio;

    for (int i = 0; atual && i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    if (!atual) return;

    no_duplo_t* novo_no = criar_no_duplo(valor);
    novo_no->proximo = atual->proximo;
    novo_no->anterior = atual;

    if (atual->proximo) atual->proximo->anterior = novo_no;

    atual->proximo = novo_no;
}

void remover_no_duplo_posicao(no_duplo_t** inicio, int posicao)
{
    if (*inicio == NULL || posicao < 0) return;

    no_duplo_t* no_para_remover = *inicio;

    for (int i = 0; no_para_remover != NULL && i < posicao; i++) {
        no_para_remover = no_para_remover->proximo;
    }

    if (no_para_remover == NULL) return;

    if (no_para_remover->anterior != NULL)  {
        no_para_remover->anterior->proximo = no_para_remover->proximo;
    } else {
        *inicio = no_para_remover->proximo;
    }

    if (no_para_remover->proximo != NULL)
    {
        no_para_remover->proximo->anterior = no_para_remover->anterior;
    }

    free(no_para_remover);
}

int tamanho_no_duplo(no_duplo_t* inicio) {
    if (inicio == NULL) return 0;

    int quantidade_de_elementos = 0;
    no_duplo_t* atual = inicio;

    for (int i = 0; atual; i++) {
        atual = atual->proximo;
        quantidade_de_elementos++;
    }

    return quantidade_de_elementos;
}

no_duplo_t* buscar_indice_no_duplo(no_duplo_t** inicio, int posicao) {
    if (posicao < 0) return NULL;
    if (posicao > tamanho_no_duplo(*inicio)) return NULL;

    no_duplo_t* atual = *inicio;

    for (int i = 0; atual && i < posicao; i++) {
        atual = atual->proximo;
    }

    if (!atual) return NULL;

    return atual;
}