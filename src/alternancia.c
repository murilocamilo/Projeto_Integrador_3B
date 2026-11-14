#include <stdio.h>
#include <stdlib.h>
#include "../include/alternancia.h"
#include "../include/lista_adjacencia.h"
#include "../include/matriz_adjacencia.h"
#include "../include/bfs_corte.h"

int executar_analise(TipoEstrutura tipo, Aresta* arestas, int total_arestas, int num_vertices, int vertice_galpao, int max_saltos) {
    if (tipo == TIPO_LISTA) {
        printf("\n[Executando com LISTA DE ADJACENCIA]\n");
        GrafoLista* g = criar_grafo_lista(num_vertices);
        
        for(int i=0; i<total_arestas; i++) {
            adicionar_aresta_lista(g, arestas[i].u, arestas[i].v, arestas[i].peso);
        }
        
        bfs_com_limite_saltos(g, vertice_galpao, max_saltos);
        
        liberar_grafo_lista(g);
        return 1;

    } else if (tipo == TIPO_MATRIZ) {
        printf("\n[Executando com MATRIZ DE ADJACENCIA]\n");
        GrafoMatriz* g = criar_grafo_matriz(num_vertices);
        
        for(int i=0; i<total_arestas; i++) {
            adicionar_aresta_matriz(g, arestas[i].u, arestas[i].v, arestas[i].peso);
        }
        
        printf("Grafo montado na matriz com sucesso. (BFS na matriz nao implementado).\n");
        
        liberar_grafo_matriz(g);
        return 1;
    }
    return 0;
}