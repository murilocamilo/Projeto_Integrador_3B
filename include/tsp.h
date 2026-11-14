#ifndef TSP_H
#define TSP_H

#include "lista_adjacencia.h"

// Executa o TSP e retorna a ordem de visitação dos vértices
void resolver_tsp_vizinho_mais_proximo(GrafoLista* g, int galpao, int* ordem_visita);

#endif