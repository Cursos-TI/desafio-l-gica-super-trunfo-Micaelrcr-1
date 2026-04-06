#include <stdio.h>

int main() {
    unsigned int populacao1 = 203080756, populacao2 = 26600000;
    unsigned int pontos_turisticos1 = 60, pontos_turisticos2 = 52;
    double area1 = 8515767.05, area2 = 7692024.00;
    double PIB1 = 10890.000, PIB2 = 8600.000;
    double Densi1, Densi2;
    char nome1[20] = "Brasil", nome2[20] = "Austrália";

    // -------- CÁLCULO DA DENSIDADE --------
    if (area1 > 0)
        Densi1 = (double) populacao1 / area1;
    else
        Densi1 = -1;

    if (area2 > 0)
        Densi2 = (double) populacao2 / area2;
    else
        Densi2 = -1;

    // -------- EXIBIÇÃO --------
    printf("\n--- DADOS DOS PAÍSES ---\n");
    printf("%s: População= %u | Área= %.2f | PIB= %.3f bi | Pontos= %u\n",
           nome1, populacao1, area1, PIB1, pontos_turisticos1);

    printf("%s: População= %u | Área= %.2f | PIB= %.3f bi | Pontos= %u\n",
           nome2, populacao2, area2, PIB2, pontos_turisticos2);

    int escolha;

    do {
        printf("\n========== MENU DE COMPARAÇÃO ==========\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Demográfica\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &escolha) != 1) {
            printf("Entrada inválida!\n");
            while (getchar() != '\n'); // limpa buffer
            continue;
        }

        switch (escolha) {
            case 1:
                printf("\n=== POPULAÇÃO ===\n");
                printf("%s: %u\n", nome1, populacao1);
                printf("%s: %u\n", nome2, populacao2);

                if (populacao1 > populacao2) {
                    printf("Vencedor: %s\n", nome1);
                } else {
                    if (populacao2 > populacao1) {
                        printf("Vencedor: %s\n", nome2);
                    } else {
                        printf("Empate!\n");
                    }
                }
                break;

            case 2:
                printf("\n=== ÁREA ===\n");
                printf("%s: %.2f\n", nome1, area1);
                printf("%s: %.2f\n", nome2, area2);

                if (area1 > area2) {
                    printf("Vencedor: %s\n", nome1);
                } else {
                    if (area2 > area1) {
                        printf("Vencedor: %s\n", nome2);
                    } else {
                        printf("Empate!\n");
                    }
                }
                break;

            case 3:
                printf("\n=== PIB (R$ BI) ===\n");
                printf("%s: %.3f\n", nome1, PIB1);
                printf("%s: %.3f\n", nome2, PIB2);

                if (PIB1 > PIB2) {
                    printf("Vencedor: %s\n", nome1);
                } else {
                    if (PIB2 > PIB1) {
                        printf("Vencedor: %s\n", nome2);
                    } else {
                        printf("Empate!\n");
                    }
                }
                break;

            case 4:
                printf("\n=== PONTOS TURÍSTICOS ===\n");
                printf("%s: %u\n", nome1, pontos_turisticos1);
                printf("%s: %u\n", nome2, pontos_turisticos2);

                if (pontos_turisticos1 > pontos_turisticos2) {
                    printf("Vencedor: %s\n", nome1);
                } else {
                    if (pontos_turisticos2 > pontos_turisticos1) {
                        printf("Vencedor: %s\n", nome2);
                    } else {
                        printf("Empate!\n");
                    }
                }
                break;

            case 5:
                printf("\n=== DENSIDADE DEMOGRÁFICA ===\n");
                printf("%s: %.2f hab/km²\n", nome1, Densi1);
                printf("%s: %.2f hab/km²\n", nome2, Densi2);
                printf("(Menor valor vence)\n");

                if (Densi1 < Densi2) {
                    printf("Vencedor: %s\n", nome1);
                } else {
                    if (Densi2 < Densi1) {
                        printf("Vencedor: %s\n", nome2);
                    } else {
                        printf("Empate!\n");
                    }
                }
                break;

            case 6:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (escolha != 6);

    return 0;
}