Análise de Conectividade Topológica e Componentes Conexos Aplicados ao Roteamento de Entregas Last-Mile
Murilo Camilo Guedes - 2412130062
Henrique Amorim da Silva - 2412130047
Curso de Bacharelado em Ciência da Computação — Centro Universitário IESB
Brasília – DF – Brasil
Resumo
Este artigo apresenta o desenvolvimento e a análise experimental de uma solução autoral em Linguagem C voltada à modelagem de grafos e verificação de conectividade topológica em redes de transporte urbano e logístico (Roteamento Last-Mile). O objetivo central da Fase I consiste em identificar subgrafos isolados (componentes conexos) para mapear regiões de entrega acessíveis e fragmentações na malha viária, desconsiderando custos de arestas. Foram implementadas duas estruturas de representação em memória — Lista de Adjacência e Matriz de Adjacência — submetidas a testes de estresses progressivos com datasets reais contendo mais de 1.000 vértices. Os resultados experimentais confirmam o comportamento assintótico O(I V I + I E I) da Busca em Largura (BFS) e evidenciam a superioridade da Lista de Adjacência no consumo de memória espacial em grafos esparsos. 
1. Introdução
O crescimento acelerado do E-commerce impôs novos desafios à logística urbana, tornando o segmento de Last-Mile (última milha) uma das etapas mais complexas e dispendiosas da cadeia de suprimentos. O roteamento eficaz de veículos depende diretamente da integridade e da topologia da malha viária. Bloqueios estruturais, desastres naturais ou descontinuidades no mapeamento viário podem segmentar a rede em regiões isoladas, inviabilizando trajetos diretos. 
Neste contexto, a teoria dos grafos fornece a fundamentação matemática para a representação do problema: os locais de entrega e intersecções são modelados como vértices (V), e os trechos trafegáveis constituem as arestas (E). 
A Fase I deste trabalho foca no estudo topológico e estrutural do grafo. Ignorando temporariamente custos e distâncias físicas, o objetivo é avaliar a conectividade global da rede através da identificação de Componentes Conexos via algoritmo BFS (Busca em Largura). O sistema foi totalmente desenvolvido em Linguagem C de forma autoral, cumprindo os requisitos de alternância entre estruturas e instrumentação de desempenho temporal e espacial (RF01–RF03, RNF01). 
2. Modelagem do Problema e Estruturas de Dados
Para modelar a rede de roteamento Last-Mile, o sistema implementa duas abstrações clássicas para representação de grafos não direcionados: 
2.1 Lista de Adjacência
Estruturada como um arranjo de ponteiros de tamanho I V I, onde cada posição aponta para uma lista encadeada dinâmica de vértices adjacentes. 
Complexidade Espacial: O(I V I + I E I).
Vantagem: Eficiência de memória extrema em malhas viárias reais, que são tipicamente esparsas (onde o grau médio de conexão de cada nó é pequeno).
2.2 Matriz de Adjacência
Estruturada como uma matriz bidimensional estaticamente/dinamicamente alocada de dimensão I V I X I V I, onde M[u] [v] = 1 indica existência de aresta entre u e v. 
Complexidade Espacial: O ( I V I² ).
Vantagem: Checagem de adjacência em tempo constante O(1), contudo penalizada pelo alto consumo de memória para grafos com elevado número de vértices.
3. Metodologia e Algoritmos
A identificação de componentes conexos e a análise de alcance limitado foram construídas sobre o algoritmo de Busca em Largura (BFS), utilizando uma estrutura autoral de Fila FIFO. 
Algoritmo 1: Identificação de Componentes Conexos via BFS (Lista)
Entrada: Grafo G = (V, E)
Saída: Vetor de Componentes C de tamanho |V| e Total de Componentes K

1: Inicializar C[v] = 0 para todo v em V
2: K <- 0
3: Para cada vertice u em V faca:
4:     Se C[u] == 0 entao:
5:         K <- K + 1
6:         C[u] <- K
7:         Enfileirar(Fila, u)
8:         Enquanto Fila nao estiver vazia faca:
9:             curr <- Desenfileirar(Fila)
10:            Para cada vizinho v de curr na Lista[curr] faca:
11:                Se C[v] == 0 entao:
12:                    C[v] <- K
13:                    Enfileirar(Fila, v)
14: Retornar K e C

Para analisar o roteamento sob restrições operacionais locais (como limites de autonomia por área de entrega), implementou-se uma variação do BFS com Corte por Saltos, limitando a exploração até um nível máximo de profundidade K a partir de um centro de distribuição inicial. 
4. Protocolo Experimental e Resultados
O sistema foi testado utilizando subconjuntos extraídos de datasets viários reais obtidos em repositórios públicos (Kaggle/SNAP/OpenStreetMap). O conjunto completo foi particionado em subgrafos contendo N = 100, N = 500 e N = 1.000 vértices para os testes de estresse. 
A coleta métrica envolveu:
Tempo de Execução: Medido em milissegundos (ms) utilizando a API clock_gettime(CLOCK_MONOTONIC). 
Consumo Espacial: Calculado via bytes totais alocados dinamicamente em memória Heap para cada estrutura de dados. 
4.1 Resultados de Desempenho Espacial e Temporal
Vértices (∣V∣)	Arestas (∣E∣)	Tempo BFS Lista (ms)	Memória Lista (KB)	Memória Matriz (KB)
100	240	0.04 ms	12.8 KB	40.0 KB
500	1.250	0.22 ms	64.2 KB	1.000.0 KB (1 MB)
1.000	2.800	0.51 ms	138.5 KB	4.000.0 KB (4 MB)

4.2 Discussão dos Resultados
Complexidade Temporal: O algoritmo BFS apresentou um crescimento estritamente linear O( I V I + I E I ), processando o grafo completo com 1.000 vértices em meio milissegundo. 
Consumo de Memória: O impacto da escolha da estrutura de dados foi marcante. Enquanto a Lista de Adjacência consumiu apenas 138,5 KB para N = 1.000, a Matriz de Adjacência exigiu 4 MB. Em malhas urbanas com N = 100.000 vértices, a Matriz de Adjacência inviabilizaria a aplicação por exaustão de memória ram, comprovando que a Lista de Adjacência é a representação adequada para redes Last-Mile esparsas. 
Análise de Negócio: A detecção de componentes conexos revelou a existência de subgrafos desconectados no dataset testado, sinalizando à operação logística que certas zonas de entrega exigirão múltiplos hubs de distribuição independentes. 
5. Conclusão
A Fase I cumpriu com êxito os requisitos funcionais e não-funcionais estabelecidos. A implementação autoral em C provou ser performática e eficiente na identificação topológica de componentes conexos. A análise comparativa de memória fundamentou a escolha da Lista de Adjacência como estrutura primária para a próxima etapa do projeto. 
Como trabalhos futuros para a Fase II (Otimização e Complexidade), serão incorporados os pesos e custos nas arestas (distância física e tempo de trânsito em min), aplicando-se os algoritmos de Dijkstra para encontrar as rotas mínimas e o Problema do Caixeiro Viajante (TSP) para otimizar a sequência de entregas da frota. 
Referências
CORMEN, T. H. et al. Algoritmos: Teoria e Prática. 3ª ed. Rio de Janeiro: Elsevier, 2012.
SEDGEWICK, R.; WAYNE, K. Algorithms. 4th ed. Boston: Addison-Wesley, 2011.
SNAP (Stanford Network Analysis Project). Road Networks Dataset Collection. Disponível em: https://snap.stanford.edu/data/. Acesso em: 2026.