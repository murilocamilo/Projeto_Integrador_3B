#include <stdio.h>
#include <time.h>
#include "../include/medidor_tempo.h"

double medir_tempo_ms(void (*funcao)(void*), void* arg) {
    struct timespec inicio, fim;
    
    // Marca o tempo de início
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    
    // Executa o algoritmo (BFS, Dijkstra, etc.)
    funcao(arg); 
    
    // Marca o tempo de fim
    clock_gettime(CLOCK_MONOTONIC, &fim);
    
    // Calcula a diferença em milissegundos (ms)
    double tempo_ms = (fim.tv_sec - inicio.tv_sec) * 1000.0 +
                      (fim.tv_nsec - inicio.tv_nsec) / 1000000.0;
                      
    return tempo_ms;
}