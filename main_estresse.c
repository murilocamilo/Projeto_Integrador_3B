#include <stdio.h>
#include <stdlib.h>
#include "include/dataset_loader.h"
#include "include/subset_generator.h"
#include "include/lista_adjacencia.h"
#include "include/matriz_adjacencia.h"
#include "include/componentes.h"
#include "include/medidor_tempo.h"
#include "include/medidor_memoria.h"

// Wrapper para o BFS (Componentes Conexos) na lista
void wrapper_bfs_lista(void* arg) {
    GrafoLista* g = (GrafoLista*)arg;
    int* componentes = (int*)malloc(g->numVertices * sizeof(int));
    encontrar_componentes_lista(g, componentes);
    free(componentes);
}

int main() {
    int total_arestas, max_vertice;
    
    // --- ALTERAÇÃO AQUI: Lendo o dataset grande ---
    Aresta* arestas = carregar_csv("dataset_grande.csv", &total_arestas, &max_vertice);
    
    if (!arestas) return 1;

    int tamanhos[] = {100, 500, 1000};
    int total_tamanhos = 3;
    
    printf("N\tEstrutura\tTempo (ms)\tMemoria (Bytes)\n");
    printf("--------------------------------------------------\n");

    for(int i = 0; i < total_tamanhos; i++) {
        int N = tamanhos[i];
        
        // Se o dataset for menor que o N solicitado, ajusta o N
        if (N > max_vertice + 1) N = max_vertice + 1; 
        
        int total_sub;
        Aresta* sub = gerar_subconjunto(arestas, total_arestas, N, &total_sub);

        if (total_sub == 0) continue;

        // --- TESTE COM LISTA ---
        GrafoLista* g_lista = criar_grafo_lista(N);
        for(int j=0; j<total_sub; j++) {
            adicionar_aresta_lista(g_lista, sub[j].u, sub[j].v, sub[j].peso);
        }
        
        size_t mem_lista = calcular_memoria_lista(g_lista, total_sub);
        double tempo_lista = medir_tempo_ms(wrapper_bfs_lista, (void*)g_lista);
        
        printf("%d\tLista\t\t%.3f\t\t%zu\n", N, tempo_lista, mem_lista);
        liberar_grafo_lista(g_lista);

        // --- TESTE COM MATRIZ ---
        GrafoMatriz* g_matriz = criar_grafo_matriz(N);
        for(int j=0; j<total_sub; j++) {
            adicionar_aresta_matriz(g_matriz, sub[j].u, sub[j].v, sub[j].peso);
        }
        
        size_t mem_matriz = calcular_memoria_matriz(g_matriz);
        // Tempo 0.0 provisório pois o BFS não foi implementado na matriz
        printf("%d\tMatriz\t\t%.3f\t\t%zu\n", N, 0.0, mem_matriz);
        liberar_grafo_matriz(g_matriz);

        liberar_arestas(sub);
    }
    liberar_arestas(arestas);
    return 0;
}