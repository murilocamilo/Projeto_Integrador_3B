#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/dataset_loader.h"

Aresta* carregar_csv(const char* nome_arquivo, int* total_arestas, int* max_vertice) {
    FILE* file = fopen(nome_arquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return NULL;
    }

    int capacidade = 1000;
    Aresta* arestas = (Aresta*)malloc(capacidade * sizeof(Aresta));
    *total_arestas = 0;
    *max_vertice = 0;

    char linha[256];
    fgets(linha, sizeof(linha), file); 

    while (fgets(linha, sizeof(linha), file)) {
        int u, v;
        float peso;
        
        if (sscanf(linha, "%d,%d,%f", &u, &v, &peso) == 3) {
            if (*total_arestas >= capacidade) {
                capacidade *= 2;
                arestas = (Aresta*)realloc(arestas, capacidade * sizeof(Aresta));
            }
            arestas[*total_arestas].u = u;
            arestas[*total_arestas].v = v;
            arestas[*total_arestas].peso = peso;
            (*total_arestas)++;

            if (u > *max_vertice) *max_vertice = u;
            if (v > *max_vertice) *max_vertice = v;
        }
    }
    fclose(file);
    return arestas;
}

void liberar_arestas(Aresta* arestas) {
    free(arestas);
}