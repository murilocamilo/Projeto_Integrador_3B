#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/dataset_loader.h"
#include "include/alternancia.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso correto: %s [lista|matriz] <caminho_do_csv>\n", argv[0]);
        printf("Exemplo: %s lista dataset.csv\n", argv[0]);
        return 1;
    }

    TipoEstrutura tipo;
    if (strcmp(argv[1], "lista") == 0) {
        tipo = TIPO_LISTA;
    } else if (strcmp(argv[1], "matriz") == 0) {
        tipo = TIPO_MATRIZ;
    } else {
        printf("Erro: Estrutura desconhecida '%s'. Use 'lista' ou 'matriz'.\n", argv[1]);
        return 1;
    }

    int total_arestas, max_vertice;
    Aresta* arestas = carregar_csv(argv[2], &total_arestas, &max_vertice);
    if (!arestas) return 1;

    int vertice_galpao = 0;
    int max_saltos = 5;

    executar_analise(tipo, arestas, total_arestas, max_vertice + 1, vertice_galpao, max_saltos);

    liberar_arestas(arestas);
    
    printf("\nAnalise finalizada com sucesso!\n");
    return 0;
}