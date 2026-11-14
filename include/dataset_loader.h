#ifndef DATASET_LOADER_H
#define DATASET_LOADER_H

typedef struct {
    int u;
    int v;
    float peso;
} Aresta;

Aresta* carregar_csv(const char* nome_arquivo, int* total_arestas, int* max_vertice);
void liberar_arestas(Aresta* arestas);

#endif