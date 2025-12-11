#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore_binaria {
    int valor;
    struct arvore_binaria* esquerda;
    struct arvore_binaria* direita;
} arvore_binaria_t;

arvore_binaria_t* criar_no(int valor){
    arvore_binaria_t* no = malloc(sizeof(arvore_binaria_t));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void destruir_arvore(arvore_binaria_t *no) {
    // Faz uma chamada recursiva para ir apagando os nós
    if (no != NULL) {
        destruir_arvore(no->esquerda);
        destruir_arvore(no->direita);
        free(no);
    }
}

arvore_binaria_t* inserir_folha(arvore_binaria_t* raiz, int valor){
    // O valor vai descendo sempre comparando se é maior ou menor que o nó, quando ele for null ele faz a inserçãop, se
    // for igual ao ultimo nó ele só ignora

    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_folha(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_folha(raiz->direita, valor);
    }

    return raiz;
}

bool busca_valor_arvore(arvore_binaria_t* raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca_valor_arvore(raiz->esquerda, valor);
    return busca_valor_arvore(raiz->direita, valor);
}

arvore_binaria_t* remover_valor_arvore(arvore_binaria_t* raiz, int valor) {
    if (raiz == NULL) return raiz;
    if (valor < raiz->valor) {
        raiz->esquerda = remover_valor_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover_valor_arvore(raiz->direita, valor);
    } else {
        if (!raiz->esquerda) {
            arvore_binaria_t* aux = raiz->direita;
            free(raiz);
            return aux;
        }
        if (!raiz->direita) {
            arvore_binaria_t* aux = raiz->esquerda;
            free(raiz);
            return aux;
        }

        arvore_binaria_t* auxiliar = encontrar_no_minimo_arvore(raiz->direita);
        raiz->valor = auxiliar->valor;
        raiz->direita = remover_valor_arvore(raiz->direita, auxiliar->valor);
    }
    return raiz;
}

arvore_binaria_t* encontrar_no_minimo_arvore(arvore_binaria_t* raiz) {
    arvore_binaria_t* atual = raiz;

    while (atual && atual->esquerda) {
        atual = atual->esquerda;
    }
    return atual;
}

int maior_valor_arvore(arvore_binaria_t* raiz) {
    if (!raiz) return -1;

    arvore_binaria_t* atual = raiz;

    while (atual->direita) {
        atual = atual->direita;
    }

    return atual->valor;
}

int menor_valor_arvore(arvore_binaria_t* raiz) {
    if (!raiz) return -1;

    arvore_binaria_t* atual = raiz;

    while (atual->esquerda) {
        atual = atual->esquerda;
    }

    return atual->valor;
}

int altura_arvore(arvore_binaria_t* raiz) {
    if (!raiz) return -1;

    int altura_esquerda = altura_arvore(raiz->esquerda);
    int altura_direita = altura_arvore(raiz->direita);

    if (altura_direita > altura_esquerda) return altura_direita + 1;
    return altura_esquerda + 1;
}

int tamanho_arvore(arvore_binaria_t* raiz) {
    if (!raiz) return 0;
    return 1 + tamanho_arvore(raiz->esquerda) + tamanho_arvore(raiz->direita);
}

void imprimir_arvore_em_ordem(arvore_binaria_t* raiz) {
    if (raiz) {
        imprimir_arvore_em_ordem(raiz->esquerda);
        printf("%d\t", raiz->valor);
        imprimir_arvore_em_ordem(raiz->direita);
    }
}
void imprimir_arvore_em_pre_ordem(arvore_binaria_t* raiz) {
    if (raiz) {
        printf("%d\t", raiz->valor);
        imprimir_arvore_em_pre_ordem(raiz->esquerda);
        imprimir_arvore_em_pre_ordem(raiz->direita);
    }
}

void imprimir_arvore_em_pos_ordem(arvore_binaria_t* raiz) {
    if (raiz) {
        imprimir_arvore_em_pos_ordem(raiz->esquerda);
        imprimir_arvore_em_pos_ordem(raiz->direita);
        printf("%d\t", raiz->valor);
    }
}

void imprimir_arvore_por_largura(arvore_binaria_t* raiz) {
    if (!raiz) return;

    int capacidade = tamanho_arvore(raiz);
    arvore_binaria_t** fila = malloc(capacidade * sizeof(arvore_binaria_t*));
    int inicio = 0, fim = 0;
    fila[fim++] = raiz;

    while (inicio < fim) {
        arvore_binaria_t* atual = fila[inicio++];
        printf("%d\t", atual->valor);

        if (atual->esquerda) fila[fim++] = atual->esquerda;
        if (atual->direita) fila[fim++] = atual->direita;
    }

    free(fila);
}