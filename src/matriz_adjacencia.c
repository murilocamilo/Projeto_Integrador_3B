#include <stdio.h>
#include <stdlib.h>
#include "../include/matriz_adjacencia.h"

GrafoMatriz* criar_grafo_matriz(int numVertices) {
    GrafoMatriz* g = (GrafoMatriz*)malloc(sizeof(GrafoMatriz));
    g->numVertices = numVertices;
    g->matriz = (float**)malloc(numVertices * sizeof(float*));
    for (int i = 0; i < numVertices; i++) {
        g->matriz[i] = (float*)calloc(numVertices, sizeof(float));
    }
    return g;
}

void adicionar_aresta_matriz(GrafoMatriz* g, int u, int v, float peso) {
    g->matriz[u][v] = peso;
    g->matriz[v][u] = peso;
}

void liberar_grafo_matriz(GrafoMatriz* g) {
    for (int i = 0; i < g->numVertices; i++) {
        free(g->matriz[i]);
    }
    free(g->matriz);
    free(g);
}