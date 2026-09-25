// medidor_tempo.h
#include <stdio.h>
#include <time.h>

double medir_tempo_ms(void (*funcao)(void*), void* arg) {
    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    
    funcao(arg); // Executa o algoritmo passado por parametro
    
    clock_gettime(CLOCK_MONOTONIC, &fim);
    
    double tempo_ms = (fim.tv_sec - inicio.tv_sec) * 1000.0 +
                      (fim.tv_nsec - inicio.tv_nsec) / 1000000.0;
    return tempo_ms;
}