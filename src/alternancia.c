#include <stdio.h>
#include <stdlib.h>
#include "../include/alternancia.h"
#include "../include/lista_adjacencia.h"
#include "../include/matriz_adjacencia.h"
#include "../include/bfs_corte.h"
#include "../include/dijkstra.h" // Fase 2 - Dijkstra
#include "../include/tsp.h"      // Fase 2 - TSP

int executar_analise(TipoEstrutura tipo, Aresta* arestas, int total_arestas, int num_vertices, int vertice_galpao, int max_saltos) {
    
    if (tipo == TIPO_LISTA) {
        printf("\n[Executando com LISTA DE ADJACENCIA]\n");
        GrafoLista* g = criar_grafo_lista(num_vertices);
        
        // 1. Monta o grafo com os pesos
        for(int i=0; i<total_arestas; i++) {
            adicionar_aresta_lista(g, arestas[i].u, arestas[i].v, arestas[i].peso);
        }
        
        // --- TESTE DA FASE 1 (BFS) ---
        // bfs_com_limite_saltos(g, vertice_galpao, max_saltos);
        
        // --- TESTE DA FASE 2 (Dijkstra) ---
        printf("\n--- ROTAS DE ENTREGA (DIJKSTRA) ---\n");
        float* distancias = dijkstra(g, vertice_galpao);
        
        // Imprime a distância até o Ponto 5 (ajuste esse número se seu dataset for maior)
        imprimir_caminho_dijkstra(g, vertice_galpao, 5, distancias);
        free(distancias);

        // --- TESTE DA FASE 2 (TSP - Vizinho Mais Próximo) ---
        int* ordem_visita = (int*)malloc(num_vertices * sizeof(int));
        resolver_tsp_vizinho_mais_proximo(g, vertice_galpao, ordem_visita);
        free(ordem_visita);
        
        liberar_grafo_lista(g);
        return 1;

    } else if (tipo == TIPO_MATRIZ) {
        printf("\n[Executando com MATRIZ DE ADJACENCIA]\n");
        GrafoMatriz* g = criar_grafo_matriz(num_vertices);
        
        for(int i=0; i<total_arestas; i++) {
            adicionar_aresta_matriz(g, arestas[i].u, arestas[i].v, arestas[i].peso);
        }
        
        printf("Grafo montado na matriz com sucesso. (Algoritmos da Fase 2 nao implementados na matriz).\n");
        
        liberar_grafo_matriz(g);
        return 1;
    }
    
    return 0;
}