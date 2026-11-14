#ifndef FILA_H
#define FILA_H

typedef struct {
    int* itens;
    int frente;
    int tras;
    int capacidade;
} Fila;

Fila* criar_fila(int capacidade);
void enfileirar(Fila* f, int item);
int desenfileirar(Fila* f);
int fila_vazia(Fila* f);
void liberar_fila(Fila* f);

#endif