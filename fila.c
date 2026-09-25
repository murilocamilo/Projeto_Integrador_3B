// fila.h / fila.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* itens;
    int frente;
    int tras;
    int capacidade;
} Fila;

Fila* criar_fila(int capacidade) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->capacidade = capacidade;
    f->itens = (int*)malloc(capacidade * sizeof(int));
    f->frente = 0;
    f->tras = 0;
    return f;
}

int fila_vazia(Fila* f) {
    return f->frente == f->tras;
}

void enfileirar(Fila* f, int valor) {
    f->itens[f->tras++] = valor;
}

int desenfileirar(Fila* f) {
    return f->itens[f->frente++];
}

void liberar_fila(Fila* f) {
    free(f->itens);
    free(f);
}