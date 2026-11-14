#include <stdio.h>
#include <stdlib.h>
#include "../include/subset_generator.h"

Aresta* gerar_subconjunto(Aresta* arestas_originais, int total_originais, int limite_N, int* total_subconjunto) {
    // Aloca o máximo possível (para não precisar usar realloc)
    Aresta* subconjunto = (Aresta*)malloc(total_originais * sizeof(Aresta));
    *total_subconjunto = 0;
    
    for (int i = 0; i < total_originais; i++) {
        // Filtra as arestas onde os vértices são menores que o limite_N
        if (arestas_originais[i].u < limite_N && arestas_originais[i].v < limite_N) {
            subconjunto[*total_subconjunto] = arestas_originais[i];
            (*total_subconjunto)++;
        }
    }
    return subconjunto;
}