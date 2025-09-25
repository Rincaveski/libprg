#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>

typedef struct pilha {
    int* elementos;
    int tamanho;
    int topo;
} pilha_t;

pilha_t* cria_pilha(int qnt) {
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(sizeof(int) * qnt);
    pilha->topo = -1;
    pilha->tamanho = qnt;

    return pilha;
}

void empilhar(pilha_t* pilha, int valor) {
    if (pilha->tamanho < pilha->topo) {
        pilha->tamanho = pilha->tamanho * 2;
        pilha->elementos = realloc(pilha->elementos, pilha->tamanho * sizeof(int));
    } else {
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;
    }
}

int desempilhar(pilha_t* pilha) {
    if (pilha->topo >= 0) {
        pilha->topo--;
        return pilha->elementos[pilha->topo + 1];
    }

    return 0;
}

int topo_pilha(pilha_t* pilha) {
    return pilha->elementos[pilha->topo];
}

int tamanho_pilha(pilha_t* pilha) {
    return pilha->tamanho;
}

void imprime_pilha(pilha_t* pilha) {
    for (int i = 0; i < pilha->topo; ++i) {
        printf("Elemento %d: %d\n", i + 1, pilha->elementos[i]);
    }
}

void destruir_pilha(pilha_t *pilha) {
    free(pilha->elementos);
    free(pilha);
}