#ifndef LISTA_ADJACENCIA_H
#define LISTA_ADJACENCIA_H

// 1. Primeiro declaramos a struct No
typedef struct No {
    int destino;
    float peso;
    struct No* proximo;
} No;

// 2. Depois declaramos a struct do Grafo
typedef struct {
    int numVertices;
    No** listas;
} GrafoLista;

// 3. As funções
GrafoLista* criar_grafo_lista(int numVertices);
void adicionar_aresta_lista(GrafoLista* g, int u, int v, float peso);
void liberar_grafo_lista(GrafoLista* g);

#endif