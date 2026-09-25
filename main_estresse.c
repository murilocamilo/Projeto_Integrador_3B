// main_estresse.c
#include <stdio.h>
#include "dataset_loader.h"
#include "subset_generator.h"
#include "lista_adjacencia.h"
#include "matriz_adjacencia.h"
#include "componentes.h"
#include "medidor_tempo.h"
#include "medidor_memoria.h"

int main() {
    int tamanhos[] = {100, 500, 1000};
    int total_tamanhos = 3;

    printf("N\tEstrutura\tTempo (ms)\tMemoria (KB)\n");
    for(int i = 0; i < total_tamanhos; i++) {
        int N = tamanhos[i];
        // 1. Carrega subconjunto
        // 2. Mede tempo e memoria na Lista
        // 3. Mede tempo e memoria na Matriz
        // 4. Imprime resultados tabulados
    }
    return 0;
}