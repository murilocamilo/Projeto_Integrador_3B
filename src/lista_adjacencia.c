#include <stdio.h>
#include <stdlib.h>
#include "../include/lista_adjacencia.h"

GrafoLista* criar_grafo_lista(int numVertices) {
    GrafoLista* g = (GrafoLista*)malloc(sizeof(GrafoLista));
    g->numVertices = numVertices;
    g->listas = (No**)malloc(numVertices * sizeof(No*));
    for (int i = 0; i < numVertices; i++) {
        g->listas[i] = NULL;
    }
    return g;
}

void adicionar_aresta_lista(GrafoLista* g, int u, int v, float peso) {
    No* novo = (No*)malloc(sizeof(No));
    novo->destino = v;
    novo->peso = peso;
    novo->proximo = g->listas[u];
    g->listas[u] = novo;
    
    No* novo_rev = (No*)malloc(sizeof(No));
    novo_rev->destino = u;
    novo_rev->peso = peso;
    novo_rev->proximo = g->listas[v];
    g->listas[v] = novo_rev;
}

void liberar_grafo_lista(GrafoLista* g) {
    for (int i = 0; i < g->numVertices; i++) {
        No* atual = g->listas[i];
        while (atual) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(g->listas);
    free(g);
}