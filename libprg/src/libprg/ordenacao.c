#include <stdlib.h>

#include "libprg/libprg.h"

void bubble_sort(int* vetor, int tamanho){
    for (int i = 0; i < tamanho - 1; i++){
        for (int j = 0; j < tamanho - 1; j++){
            if (vetor[j] > vetor[j + 1]){
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void insertion_sort(int* vetor, int tamanho){
    for (int i = 1; i < tamanho; i++) {
        int aux = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > aux){
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = aux;
    }
}

void selection_sort(int* vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        int index_menor = i;

        for (int j = i + 1; j < tamanho; j++){
            if (vetor[j] < vetor[index_menor]){
                index_menor = j;
            }
        }

        if (index_menor != i) {
            int aux = vetor[i];
            vetor[i] = vetor[index_menor];
            vetor[index_menor] = aux;
        }
    }
}

void merge(int* vetor, int esquerda, int meio, int direita){
    int i, j, k;

    int vetor_esquerda = meio - esquerda + 1;
    int vetor_direita = direita - meio;

    int *l = malloc(vetor_esquerda * sizeof(int));
    int *r = malloc(vetor_direita * sizeof(int));

    for (i = 0; i < vetor_esquerda; i++){
        l[i] = vetor[esquerda + i];
    }
    for (j = 0; j < vetor_direita; j++){
        r[j] = vetor[meio + 1 + j];
    }

    i = 0, j = 0; k = esquerda;

    while (i < vetor_esquerda && j < vetor_direita){
        if (l[i] <= r[j]) {
            vetor[k] = l[i];
            i++;
        } else {
            vetor[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < vetor_esquerda) {
        vetor[k] = l[i];
        i++;
        k++;
    }

    while (j < vetor_direita) {
        vetor[k] = r[j];
        j++;
        k++;
    }

    free(l);
    free(r);
}

void merge_sort(int* vetor, int esquerda, int direita) {
    int meio = (esquerda + direita) / 2;

    if (esquerda < direita) {
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);

        merge(vetor, esquerda, meio, direita);
    }
}

int particiona(int* vetor, int esquerda, int direita){
    int pivo = vetor[direita];
    int i = esquerda - 1;

    for (int j = esquerda; j < direita; j++){
        if (vetor[j] <= pivo){
            i++;
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    int aux = vetor[i + 1];
    vetor[i + 1] = vetor[direita];
    vetor[direita] = aux;

    return i + 1;
}

void quick_sort(int* vetor, int esquerda, int direita) {
    if (esquerda < direita){
        int pi = particiona(vetor, esquerda, direita);

        quick_sort(vetor, esquerda, pi - 1);
        quick_sort(vetor, pi + 1, direita);
    }
}