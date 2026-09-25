// dataset_loader.h / dataset_loader.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u;
    int v;
} Aresta;

// Lê o arquivo CSV no formato "origem,destino"
Aresta* carregar_dataset(const char* caminho_arquivo, int* total_arestas, int* max_vertice) {
    FILE* arquivo = fopen(caminho_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", caminho_arquivo);
        return NULL;
    }

    int capacidade = 1000;
    Aresta* arestas = (Aresta*)malloc(capacidade * sizeof(Aresta));
    *total_arestas = 0;
    *max_vertice = 0;

    int u, v;
    while (fscanf(arquivo, "%d,%d", &u, &v) == 2) {
        if (*total_arestas >= capacidade) {
            capacidade *= 2;
            arestas = (Aresta*)realloc(arestas, capacidade * sizeof(Aresta));
        }
        arestas[*total_arestas].u = u;
        arestas[*total_arestas].v = v;
        (*total_arestas)++;

        if (u > *max_vertice) *max_vertice = u;
        if (v > *max_vertice) *max_vertice = v;
    }

    fclose(arquivo);
    return arestas;
}