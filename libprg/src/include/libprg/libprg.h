#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct pilha pilha_t;

pilha_t* cria_pilha(int qnt);
void empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
void imprime_pilha(pilha_t* pilha);
void destruir(pilha_t *pilha);

#endif
