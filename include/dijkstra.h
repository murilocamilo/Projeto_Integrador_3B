#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "lista_adjacencia.h"

// Retorna um vetor com as menores distâncias a partir da origem
float* dijkstra(GrafoLista* g, int origem);

// Função auxiliar para mostrar o resultado na tela
void imprimir_caminho_dijkstra(GrafoLista* g, int origem, int destino, float* distancias);

#endif