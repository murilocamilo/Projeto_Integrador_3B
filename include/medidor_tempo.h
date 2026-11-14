#ifndef MEDIDOR_TEMPO_H
#define MEDIDOR_TEMPO_H

// Função que mede o tempo de execução de qualquer outra função
double medir_tempo_ms(void (*funcao)(void*), void* arg);

#endif