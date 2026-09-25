// componentes.c
#include "lista_adjacencia.h"
#include "fila.h"

int encontrar_componentes_lista(GrafoLista* g, int* componentes) {
    int total_componentes = 0;
    for (int i = 0; i < g->numVertices; i++) componentes[i] = 0;

    Fila* f = criar_fila(g->numVertices);

    for (int i = 0; i < g->numVertices; i++) {
        if (componentes[i] == 0) {
            total_componentes++;
            componentes[i] = total_componentes;
            enfileirar(f, i);

            while (!fila_vazia(f)) {
                int u = desenfileirar(f);
                No* temp = g->listas[u];
                while (temp) {
                    int v = temp->destino;
                    if (componentes[v] == 0) {
                        componentes[v] = total_componentes;
                        enfileirar(f, v);
                    }
                    temp = temp->proximo;
                }
            }
        }
    }
    liberar_fila(f);
    return total_componentes;
}