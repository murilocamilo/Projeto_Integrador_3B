// subset_generator.c
#include "dataset_loader.h"

// Filtra e retorna apenas as arestas cujos vértices sejam menores que limite_N
Aresta* gerar_subconjunto(Aresta* arestas_originais, int total_originais, int limite_N, int* total_subconjunto) {
    Aresta* subconjunto = (Aresta*)malloc(total_originais * sizeof(Aresta));
    *total_subconjunto = 0;

    for (int i = 0; i < total_originais; i++) {
        if (arestas_originais[i].u < limite_N && arestas_originais[i].v < limite_N) {
            subconjunto[*total_subconjunto] = arestas_originais[i];
            (*total_subconjunto)++;
        }
    }
    return subconjunto;
}