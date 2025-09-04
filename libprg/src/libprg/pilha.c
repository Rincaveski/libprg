#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>

pilha_t* cria_pilha(int qnt) {
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(sizeof(double) * qnt);
    pilha->topo = -1;
    pilha->tamanho = qnt;

    return pilha;
}

void adiciona_elemento(pilha_t* pilha, double valor) {
    if (pilha->tamanho < pilha->topo) {
        printf("Pilha já está no limite");
    } else {
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;
    }

}

void remove_item(pilha_t* pilha) {
    if (pilha->topo >= 0) {
        pilha->topo--;
        printf("Elemento removido do topo da fila.\n");
    } else {
        printf("Pilha já está limpa");
    }
}

void imprime_pilha(pilha_t* pilha) {
    for (int i = 0; i < pilha->topo; ++i) {
        printf("Elemento %d: %d\n", i + 1, pilha->elementos[i]);
    }
}