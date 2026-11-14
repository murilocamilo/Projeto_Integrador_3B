#include <stdio.h>
#include <stdlib.h>
#include "../include/fila.h"

Fila* criar_fila(int capacidade) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->itens = (int*)malloc(capacidade * sizeof(int));
    f->frente = 0;
    f->tras = 0;
    f->capacidade = capacidade;
    return f;
}

void enfileirar(Fila* f, int item) {
    // Se a fila encheu, a gente para (para não estourar a memória)
    if (f->tras == f->capacidade) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->itens[f->tras] = item;
    f->tras++;
}

int desenfileirar(Fila* f) {
    if (fila_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int item = f->itens[f->frente];
    f->frente++;
    return item;
}

int fila_vazia(Fila* f) {
    return (f->frente == f->tras);
}

void liberar_fila(Fila* f) {
    free(f->itens);
    free(f);
}