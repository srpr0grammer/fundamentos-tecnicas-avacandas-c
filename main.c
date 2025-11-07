#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char estado[30];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *c) {
    printf("\n[CADASTRO DE CARTA]\n");

    printf("Informe o estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Informe o código da carta (ex: A01): ");
    scanf(" %s", c->codigo);

    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", c->cidade);

    printf("Informe a população: ");
    scanf("%d", &c->populacao);

    printf("Informe a área (em km²): ");
    scanf("%f", &c->area);

    printf("Informe o PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    // cálculos do módulo aventureiro
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao;

    printf("\nCarta cadastrada com sucesso!\n");
}

// Função para exibir uma carta
void exibirCarta(Carta c) {
    printf("\n=== CARTA %s ===\n", c.codigo);
    printf("Estado: %s\n", c.estado);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
}

// Função para comparar duas cartas (módulo mestre)
void compararCartas(Carta c1, Carta c2) {
    printf("\n[COMPARAÇÃO ENTRE CARTAS]\n");

    printf("\n1️⃣ População: %s\n", (c1.populacao > c2.populacao) ? c1.cidade : c2.cidade);
    printf("2️⃣ Área: %s\n", (c1.area > c2.area) ? c1.cidade : c2.cidade);
    printf("3️⃣ PIB: %s\n", (c1.pib > c2.pib) ? c1.cidade : c2.cidade);
    printf("4️⃣ Pontos Turísticos: %s\n", (c1.pontosTuristicos > c2.pontosTuristicos) ? c1.cidade : c2.cidade);
    printf("5️⃣ PIB per capita: %s\n", (c1.pibPerCapita > c2.pibPerCapita) ? c1.cidade : c2.cidade);
    printf("6️⃣ Densidade populacional (menor vence): %s\n", (c1.densidadePopulacional < c2.densidadePopulacional) ? c1.cidade : c2.cidade);
}

int main() {
    int opcao;
    Carta carta1, carta2;
    int cadastradas = 0;

    do {
        printf("\n=== SUPER TRUNFO - PAÍSES (TECHNOVA) ===\n");
        printf("1. Cadastrar carta 1\n");
        printf("2. Cadastrar carta 2\n");
        printf("3. Exibir cartas\n");
        printf("4. Comparar cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarCarta(&carta1);
                cadastradas++;
                break;
            case 2:
                cadastrarCarta(&carta2);
                cadastradas++;
                break;
            case 3:
                if (cadastradas >= 1) {
                    exibirCarta(carta1);
                    if (cadastradas > 1) exibirCarta(carta2);
                } else {
                    printf("Nenhuma carta cadastrada ainda!\n");
                }
                break;
            case 4:
                if (cadastradas >= 2) {
                    compararCartas(carta1, carta2);
                } else {
                    printf("Cadastre as duas cartas primeiro!\n");
                }
                break;
            case 0:
                printf("Encerrando o jogo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}
