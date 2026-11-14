#include <stdio.h>
#include <stdlib.h>
#include "../include/medidor_memoria.h"
#include "../include/lista_adjacencia.h"
#include "../include/matriz_adjacencia.h"

// Calcula a memória da Lista de Adjacência (em bytes)
size_t calcular_memoria_lista(GrafoLista* g, int total_arestas) {
    // Memória da struct principal + vetor de ponteiros
    size_t mem_cabecalho = sizeof(GrafoLista) + (g->numVertices * sizeof(No*));
    
    // Memória dos nós (multiplicado por 2 porque o grafo é não-direcionado)
    size_t mem_nos = total_arestas * 2 * sizeof(No); 
    
    return mem_cabecalho + mem_nos;
}

// Calcula a memória da Matriz de Adjacência (em bytes)
size_t calcular_memoria_matriz(GrafoMatriz* g) {
    // Memória da struct principal + vetor de ponteiros para as linhas
    size_t mem_ponteiros = sizeof(GrafoMatriz) + (g->numVertices * sizeof(float*));
    
    // Memória dos dados (matriz N x N de floats)
    size_t mem_dados = g->numVertices * g->numVertices * sizeof(float);
    
    return mem_ponteiros + mem_dados;
}