#ifndef MEDIDOR_MEMORIA_H
#define MEDIDOR_MEMORIA_H

#include <stddef.h> // Necessário para usar o size_t
#include "lista_adjacencia.h"
#include "matriz_adjacencia.h"

// Calcula a memória TEÓRICA (matemática) da Lista
size_t calcular_memoria_lista(GrafoLista* g, int total_arestas);

// Calcula a memória TEÓRICA (matemática) da Matriz
size_t calcular_memoria_matriz(GrafoMatriz* g);

#endif