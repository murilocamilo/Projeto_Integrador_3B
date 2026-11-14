#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "../include/dijkstra.h"
#include "../include/lista_adjacencia.h"

// Função para achar o vértice com a menor distância ainda não visitado
int vertice_min_distancia(float* dist, int* visitados, int numVertices) {
    float min = FLT_MAX;
    int min_index = -1;
    for (int v = 0; v < numVertices; v++) {
        if (visitados[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

float* dijkstra(GrafoLista* g, int origem) {
    int V = g->numVertices;
    float* dist = (float*)malloc(V * sizeof(float));
    int* visitados = (int*)calloc(V, sizeof(int));

    // Inicializa as distâncias com "infinito"
    for (int i = 0; i < V; i++) {
        dist[i] = FLT_MAX;
    }
    dist[origem] = 0.0;

    for (int count = 0; count < V - 1; count++) {
        int u = vertice_min_distancia(dist, visitados, V);
        if (u == -1) break; // Todos os vértices alcançáveis já foram visitados

        visitados[u] = 1;

        // Relaxamento das arestas vizinhas
        No* temp = g->listas[u];
        while (temp) {
            int v = temp->destino;
            float peso = temp->peso;

            if (visitados[v] == 0 && dist[u] != FLT_MAX && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }
            temp = temp->proximo;
        }
    }

    free(visitados);
    return dist;
}

void imprimir_caminho_dijkstra(GrafoLista* g, int origem, int destino, float* distancias) {
    if (distancias[destino] == FLT_MAX) {
        printf("Nao existe rota do Galpao (%d) ate o Ponto (%d).\n", origem, destino);
    } else {
        printf("Menor distancia do Galpao (%d) ate o Ponto (%d): %.2f KM\n", 
               origem, destino, distancias[destino]);
    }
} 