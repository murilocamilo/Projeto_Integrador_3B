// matriz_adjacencia.h / matriz_adjacencia.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numVertices;
    int** matriz;
} GrafoMatriz;

GrafoMatriz* criar_grafo_matriz(int numVertices) {
    GrafoMatriz* g = (GrafoMatriz*)malloc(sizeof(GrafoMatriz));
    g->numVertices = numVertices;
    g->matriz = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        g->matriz[i] = (int*)calloc(numVertices, sizeof(int));
    }
    return g;
}

void adicionar_aresta_matriz(GrafoMatriz* g, int u, int v) {
    g->matriz[u][v] = 1;
    g->matriz[v][u] = 1;
}

void liberar_grafo_matriz(GrafoMatriz* g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->matriz[i]);
    }
    free(g->matriz);
    free(g);
}