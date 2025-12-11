#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>

typedef struct pilha {
    int* elementos;
    int capacidade;
    int topo;
} pilha_t;

pilha_t* cria_pilha(int qnt) {
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(sizeof(int) * qnt);
    pilha->topo = -1;
    pilha->capacidade = qnt;

    return pilha;
}

void empilhar(pilha_t* pilha, int valor) {
    if (pilha->capacidade <= pilha->topo + 1) {
        pilha->capacidade = pilha->capacidade * 2;
        pilha->elementos = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;
}

int desempilhar(pilha_t* pilha) {
    if (pilha->topo >= 0) {
        pilha->topo--;
        return pilha->elementos[pilha->topo + 1];
    }

    return 0;
}

int topo_pilha(pilha_t* pilha) {
    if (pilha->topo >= 0) {
        return pilha->elementos[pilha->topo];
    }
    return 0;
}

int tamanho_pilha(pilha_t* pilha) {
    return pilha->topo + 1;
}

void imprime_pilha(pilha_t* pilha) {
    for (int i = 0; i <= pilha->topo; ++i) {
        printf("Elemento %d: %d\n", i + 1, pilha->elementos[i]);
    }
}

int imprime_pilha_indice(pilha_t* pilha, int indice) {
    if (pilha->topo >= indice) {
        return pilha->elementos[indice];
    }

    return 0;
}

void imprime_pilha_hanoi(pilha_t* esquerda, pilha_t* meio, pilha_t* direita, int n) {
    for (int i = n - 1; i >= 0; --i) {
        printf("%d %d %d\n", imprime_pilha_indice(esquerda, i), imprime_pilha_indice(meio, i), imprime_pilha_indice(direita, i));
    }
}

void destruir_pilha(pilha_t *pilha) {
    free(pilha->elementos);
    free(pilha);
}
