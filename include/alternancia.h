#ifndef ALTERNANCIA_H
#define ALTERNANCIA_H

#include "dataset_loader.h"

typedef enum { TIPO_LISTA, TIPO_MATRIZ } TipoEstrutura;

int executar_analise(TipoEstrutura tipo, Aresta* arestas, int total_arestas, int num_vertices, int vertice_galpao, int max_saltos);

#endif