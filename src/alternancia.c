#include <stdio.h>
#include <stdlib.h>
#include "../include/alternancia.h"
#include "../include/lista_adjacencia.h"
#include "../include/matriz_adjacencia.h"
#include "../include/bfs_corte.h"
#include "../include/dijkstra.h"
#include "../include/tsp.h"
#include "../include/medidor_tempo.h"

// --- WRAPPERS PARA MEDIÇÃO DE TEMPO ---
typedef struct {
    GrafoLista* g;
    int origem;
    float* distancias;
} ArgsDijkstra;

void wrapper_dijkstra(void* arg) {
    ArgsDijkstra* args = (ArgsDijkstra*)arg;
    args->distancias = dijkstra(args->g, args->origem);
}

typedef struct {
    GrafoLista* g;
    int galpao;
    int* ordem_visita;
} ArgsTSP;

void wrapper_tsp(void* arg) {
    ArgsTSP* args = (ArgsTSP*)arg;
    resolver_tsp_vizinho_mais_proximo(args->g, args->galpao, args->ordem_visita);
}

// --- FUNÇÃO PRINCIPAL ---
int executar_analise(TipoEstrutura tipo, Aresta* arestas, int total_arestas, int num_vertices, int vertice_galpao, int max_saltos) {
    
    if (tipo == TIPO_LISTA) {
        printf("\n[Executando com LISTA DE ADJACENCIA]\n");
        GrafoLista* g = criar_grafo_lista(num_vertices);
        
        for(int i=0; i<total_arestas; i++) {
            adicionar_aresta_lista(g, arestas[i].u, arestas[i].v, arestas[i].peso);
        }
        
        // --- 1. DIJKSTRA + MEDIÇÃO DE TEMPO ---
        ArgsDijkstra args_dij;
        args_dij.g = g;
        args_dij.origem = vertice_galpao;
        args_dij.distancias = NULL;

        double tempo_dijkstra = medir_tempo_ms(wrapper_dijkstra, &args_dij);
        
        printf("\n--- ROTAS DE ENTREGA (DIJKSTRA) ---\n");
        imprimir_caminho_dijkstra(g, vertice_galpao, 5, args_dij.distancias);
        printf("[Benchmarking] Tempo de execucao do Dijkstra: %.3f ms\n", tempo_dijkstra);
        free(args_dij.distancias);

        // --- 2. TSP + MEDIÇÃO DE TEMPO ---
        int* ordem_visita = (int*)malloc(num_vertices * sizeof(int));
        ArgsTSP args_tsp;
        args_tsp.g = g;
        args_tsp.galpao = vertice_galpao;
        args_tsp.ordem_visita = ordem_visita;

        double tempo_tsp = medir_tempo_ms(wrapper_tsp, &args_tsp);
        
        printf("\n[Benchmarking] Tempo de execucao do TSP: %.3f ms\n", tempo_tsp);

        // --- 3. ANÁLISE FINANCEIRA (Custo de Gasolina) ---
        // Vamos calcular a distância total percorrida na rota do TSP
        float distancia_total = 0.0;
        for (int i = 0; i < num_vertices - 1; i++) {
            int u = ordem_visita[i];
            int v = ordem_visita[i+1];
            // Busca o peso da aresta entre u e v
            No* temp = g->listas[u];
            while(temp) {
                if(temp->destino == v) {
                    distancia_total += temp->peso;
                    break;
                }
                temp = temp->proximo;
            }
        }

        printf("\n--- ANALISE FINANCEIRA (LAST-MILE) ---\n");
        printf("Distancia total percorrida pelo motoboy: %.2f KM\n", distancia_total);
        
        // Premissas de custo (Moto faz 35 km/L, Gasolina a R$ 5,80/L)
        float consumo_km_l = 35.0;
        float preco_gasolina = 5.80;
        float litros_gastos = distancia_total / consumo_km_l;
        float custo_total = litros_gastos * preco_gasolina;
        
        printf("Consumo estimado: %.2f Litros\n", litros_gastos);
        printf("Custo total de combustivel: R$ %.2f\n", custo_total);

        free(ordem_visita);
        liberar_grafo_lista(g);
        return 1;

    } else if (tipo == TIPO_MATRIZ) {
        // Matriz continua igual
        return 1;
    }
    
    return 0;
}