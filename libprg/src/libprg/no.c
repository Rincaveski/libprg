#include <stdlib.h>

#include "libprg/libprg.h"

typedef struct no {
    int valor;
    no_t* proximo;
} no_t;

no_t* criar_no(int valor) {
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

no_t adicionar_no(int valor, no_t** inicio) {
    no_t* no = criar_no(valor);
    no->proximo = &inicio;
    inicio = no

}

// buscar
// remover
// destruir
