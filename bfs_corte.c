// bfs_corte.c
#include "lista_adjacencia.h"
#include "fila.h"

void bfs_com_limite_saltos(GrafoLista* g, int vertice_inicio, int max_saltos) {
    int* distancias = (int*)malloc(g->numVertices * sizeof(int));
    for (int i = 0; i < g->numVertices; i++) distancias[i] = -1;

    Fila* f = criar_fila(g->numVertices);
    
    distancias[vertice_inicio] = 0;
    enfileirar(f, vertice_inicio);

    printf("Alcance Last-Mile a partir de %d (Max %d saltos):\n", vertice_inicio, max_saltos);

    while (!fila_vazia(f)) {
        int u = desenfileirar(f);
        if (distancias[u] >= max_saltos) continue;

        No* temp = g->listas[u];
        while (temp) {
            int v = temp->destino;
            if (distancias[v] == -1) {
                distancias[v] = distancias[u] + 1;
                printf(" - Ponto %d alcancavel em %d salto(s)\n", v, distancias[v]);
                enfileirar(f, v);
            }
            temp = temp->proximo;
        }
    }

    free(distancias);
    liberar_fila(f);
}