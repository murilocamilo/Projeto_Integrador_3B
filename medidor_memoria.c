// medidor_memoria.h
#include <stdio.h>
#include "lista_adjacencia.h"
#include "matriz_adjacencia.h"

size_t calcular_memoria_lista(GrafoLista* g, int total_arestas) {
    size_t mem_cabecalho = sizeof(GrafoLista) + (g->numVertices * sizeof(No*));
    size_t mem_nos = total_arestas * 2 * sizeof(No); // Grafo nao-direcionado
    return mem_cabecalho + mem_nos;
}

size_t calcular_memoria_matriz(GrafoMatriz* g) {
    size_t mem_ponteiros = sizeof(GrafoMatriz) + (g->numVertices * sizeof(int*));
    size_t mem_dados = g->numVertices * g->numVertices * sizeof(int);
    return mem_ponteiros + mem_dados;
}