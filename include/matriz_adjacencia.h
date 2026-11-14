#ifndef MATRIZ_ADJACENCIA_H
#define MATRIZ_ADJACENCIA_H

typedef struct {
    int numVertices;
    float** matriz;
} GrafoMatriz;

GrafoMatriz* criar_grafo_matriz(int numVertices);
void adicionar_aresta_matriz(GrafoMatriz* g, int u, int v, float peso);
void liberar_grafo_matriz(GrafoMatriz* g);

#endif