#include <stdio.h>

#define MAX_ORIGENS 100
#define MAX_DESTINOS 100

void problemaTransporte(int origens, int destinos, int supply[], int demand[], int cost[][MAX_DESTINOS], int x[][MAX_DESTINOS]) {
    int i, j, q;

    // Inicializa a matriz x com zeros
    for (i = 0; i < origens; i++) {
        for (j = 0; j < destinos; j++) {
            x[i][j] = 0;
        }
    }

    // Enquanto houver oferta ou demanda não atendida
    while (1) {
        int ofertaMaxima = -1, demandaMaxima = -1;
        int indiceOfertaMaxima = -1, indiceDemandaMaxima = -1;

        // Procura a origem com a maior oferta não atendida
        for (i = 0; i < origens; i++) {
            if (supply[i] > 0 && (ofertaMaxima == -1 || supply[i] > ofertaMaxima)) {
                ofertaMaxima = supply[i];
                indiceOfertaMaxima = i;
            }
        }

        // Procura o destino com a maior demanda não atendida
        for (j = 0; j < destinos; j++) {
            if (demand[j] > 0 && (demandaMaxima == -1 || demand[j] > demandaMaxima)) {
                demandaMaxima = demand[j];
                indiceDemandaMaxima = j;
            }
        }

        // Se não há oferta ou demanda não atendida, encerra o loop
        if (indiceOfertaMaxima == -1 || indiceDemandaMaxima == -1)
            break;

        // Calcula a quantidade a ser transportada
        q = (supply[indiceOfertaMaxima] < demand[indiceDemandaMaxima]) ? supply[indiceOfertaMaxima] : demand[indiceDemandaMaxima];

        // Atualiza a matriz x
        x[indiceOfertaMaxima][indiceDemandaMaxima] = q;

        // Atualiza as ofertas e demandas restantes
        supply[indiceOfertaMaxima] -= q;
        demand[indiceDemandaMaxima] -= q;
    }
}

int main() {
    int origens, destinos;
    int supply[MAX_ORIGENS];
    int demand[MAX_DESTINOS];
    int cost[MAX_ORIGENS][MAX_DESTINOS];
    int x[MAX_ORIGENS][MAX_DESTINOS];
    int i, j;

    // Leitura dos dados de entrada
    printf("Informe o número de origens: ");
    scanf("%d", &origens);

    printf("Informe o número de destinos: ");
    scanf("%d", &destinos);

    printf("Informe a oferta de cada origem:\n");
    for (i = 0; i < origens; i++) {
        scanf("%d", &supply[i]);
    }

    printf("Informe a demanda de cada destino:\n");
    for (j = 0; j < destinos; j++) {
        scanf("%d", &demand[j]);
    }

    printf("Informe o custo de transporte de cada origem para cada destino:\n");
    for (i = 0; i < origens; i++) {
        for (j = 0; j < destinos; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Chama a função para resolver o problema do transporte
    problemaTransporte(origens, destinos, supply, demand, cost, x);

    // Imprime a matriz resultado
    printf("\nMatriz de transporte:\n");
    for (i = 0; i < origens; i++) {
        for (j = 0; j < destinos; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }

    return 0;
}

