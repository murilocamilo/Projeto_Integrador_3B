#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    FILE* f = fopen("dataset_grande.csv", "w");
    
    if (f == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    fprintf(f, "origem,destino,peso\n");
    
    // Gera 3000 arestas aleatórias para 1000 vértices
    for (int i = 0; i < 3000; i++) {
        int u = rand() % 1000;
        int v = rand() % 1000;
        float peso = (rand() % 50 + 1) / 10.0; // Peso entre 0.1 e 5.0
        
        if (u != v) { // Evita laços (vértice ligado a ele mesmo)
            fprintf(f, "%d,%d,%.1f\n", u, v, peso);
        }
    }
    
    fclose(f);
    printf("Arquivo dataset_grande.csv criado com sucesso! (3000 arestas)\n");
    return 0;
}