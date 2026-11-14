#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "../include/tsp.h"
#include "../include/lista_adjacencia.h"

// Função auxiliar para achar o peso entre dois vértices na Lista de Adjacência
float obter_distancia_lista(GrafoLista* g, int u, int v) {
    No* temp = g->listas[u];
    while (temp) {
        if (temp->destino == v) {
            return temp->peso;
        }
        temp = temp->proximo;
    }
    return FLT_MAX; // Se não houver conexão direta
}

void resolver_tsp_vizinho_mais_proximo(GrafoLista* g, int galpao, int* ordem_visita) {
    int V = g->numVertices;
    int* visitados = (int*)calloc(V, sizeof(int));
    
    int atual = galpao;
    ordem_visita[0] = atual;
    visitados[atual] = 1;
    
    printf("\n--- SEQUENCIAMENTO DE ENTREGAS (TSP) ---\n");
    printf("Iniciando no Galpao (%d)\n", atual);

    for (int passo = 1; passo < V; passo++) {
        int proximo_vertice = -1;
        float menor_distancia = FLT_MAX;

        // Procura o vizinho mais próximo não visitado
        No* temp = g->listas[atual];
        while (temp) {
            int vizinho = temp->destino;
            if (!visitados[vizinho] && temp->peso < menor_distancia) {
                menor_distancia = temp->peso;
                proximo_vertice = vizinho;
            }
            temp = temp->proximo;
        }

        // Se não houver caminho direto, o motoboy está "preso" (grafo desconexo)
        if (proximo_vertice == -1) {
            printf("Nao ha mais rotas diretas a partir do Ponto %d. Fim das entregas.\n", atual);
            break;
        }

        // Vai para o próximo
        visitados[proximo_vertice] = 1;
        ordem_visita[passo] = proximo_vertice;
        printf(" -> Indo para o Ponto %d (Distancia: %.2f KM)\n", proximo_vertice, menor_distancia);
        
        atual = proximo_vertice;
    }

    free(visitados);
}