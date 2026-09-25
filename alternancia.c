// alternancia.h
typedef enum { TIPO_LISTA, TIPO_MATRIZ } TipoEstrutura;

void executar_analise(TipoEstrutura tipo, Aresta* arestas, int total_arestas, int num_vertices) {
    if (tipo == TIPO_LISTA) {
        GrafoLista* g = criar_grafo_lista(num_vertices);
        for(int i=0; i<total_arestas; i++) adicionar_aresta_lista(g, arestas[i].u, arestas[i].v);
        // Processa via Lista
        liberar_grafo_lista(g);
    } else {
        GrafoMatriz* g = criar_grafo_matriz(num_vertices);
        for(int i=0; i<total_arestas; i++) adicionar_aresta_matriz(g, arestas[i].u, arestas[i].v);
        // Processa via Matriz
        liberar_grafo_matriz(g);
    }
}