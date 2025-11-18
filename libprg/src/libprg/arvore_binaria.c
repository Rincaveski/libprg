#include <stdbool.h>
#include <stdlib.h>

typedef struct no_b {
    int valor;
    struct no_b ∗esquerda;
    struct no_b ∗direita;
} no_binario_t;

no_binario_t ∗criar_no(int valor){
    no_binario_t ∗no = (no_binario_t ∗) malloc(sizeof(no_binario_t));
    no−>valor = valor;
    no−>esquerda = no−>direita = NULL;
    return no;
}

void destruir_no(no_binario_t ∗no) {
    if (no != NULL) {
        destruir_no(no−>esquerda);
        destruir_no(no−>direita);
        free(no);
    }
}

// todo nó é raiz de uma subárvore
no_binario_t ∗inserir_valor(no_binario_t ∗raiz, int valor){
    if (raiz == NULL) {
        return criar_no(valor);
    } else if (valor < raiz−>valor) {
        raiz−>esquerda = inserir_valor(raiz−>esquerda, valor);
    } else if (valor > raiz−>valor) {
        raiz−>direita = inserir_valor(raiz−>direita, valor);
    }
    return raiz;
}
bool busca(no_binario_t ∗raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz−>valor) return true;
    if (valor < raiz−>valor) return busca(raiz−>esquerda, valor);
    return busca(raiz−>direita, valor);
}

no_binario_t ∗remover_valor(no_binario_t ∗raiz, int valor){
    if (raiz == NULL) return raiz;
    if (valor < raiz−>valor) {
        raiz−>esquerda = remover_valor(raiz.esquerda, valor);
    } else if (valor > raiz−>valor) {
        raiz−>direita = remover_valor(raiz.direita, valor);
    } else {
        // IF nó folha ou nó com um filho
        // ELSE nó com dois filhos
    }
    return raiz;
}