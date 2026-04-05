#include <stdio.h>

int main() {
    unsigned int populacao1, populacao2, pontos_turisticos1, pontos_turisticos2;
    float area1, area2, PIB1, PIB2, PPC1, PPC2, Densi1, Densi2; 
    char estado1[20], estado2[20], codigo1[20], codigo2[20], nome1[50], nome2[50];

    
    // -------- PRIMEIRA CIDADE --------
    printf("Estado da primeira carta: Ex: A\n");
    scanf("%5s", estado1);

    printf("Codigo da primeira carta: Ex: A01\n");
    scanf("%19s", codigo1);

    printf("Nome da cidade: Ex: Recife\n");
    scanf(" %19[^\n]", nome1);

    printf("Populacao: Ex: 1200000\n");
    scanf("%u", &populacao1);

    printf("Area (km2): Ex: 1500.00\n");
    scanf("%f", &area1);

    printf("PIB: Ex: 5000000.00\n");
    scanf("%f", &PIB1);

    printf("Pontos turisticos: Ex: 50\n");
    scanf("%d", &pontos_turisticos1);

    // -------- SEGUNDA CIDADE --------
    printf("\nEstado da segunda carta: Ex: B\n");
    scanf("%5s", estado2);

    printf("Codigo da segunda carta: Ex: B01\n");
    scanf("%19s", codigo2);

    printf("Nome da cidade: Ex: Sergipe\n");
    scanf(" %19[^\n]", nome2);

    printf("Populacao: Ex: 2500000\n");
    scanf("%u", &populacao2);

    printf("Area (km2): Ex: 2000.00\n");
    scanf("%f", &area2);

    printf("PIB: Ex: 8000000.00\n");
    scanf("%f", &PIB2);
    
    printf("Pontos turisticos: Ex: 60\n");
    scanf("%d", &pontos_turisticos2);

    // -------- CÁLCULOS --------
    if (populacao1 > 0) PPC1 = PIB1 / populacao1;
    else PPC1 = 0;

    if (populacao2 > 0) PPC2 = PIB2 / populacao2;
    else PPC2 = 0;

    if (area1 > 0) Densi1 = populacao1 / area1;
    else Densi1 = 0;

    if (area2 > 0) Densi2 = populacao2 / area2;
    else Densi2 = 0;

    // -------- EXIBIÇÃO --------
    printf("\n--- DADOS DAS CIDADES ---\n");
    printf("%s: Populacao= %u | Area= %.2f | PIB= %.2f | Pontos= %d\n",
           nome1, populacao1, area1, PIB1, pontos_turisticos1);

    printf("%s: Populacao= %u | Area= %.2f | PIB= %.2f | Pontos= %d\n",
           nome2, populacao2, area2, PIB2, pontos_turisticos2);

    // -------- COMPARAÇÕES --------

    // População
    if (populacao1 > populacao2)
        printf("\nMaior populacao: %s\n", nome1);
    else if (populacao2 > populacao1)
        printf("\nMaior populacao: %s\n", nome2);
    else
        printf("\nEmpate em populacao\n");

    // Área
    if (area1 > area2)
        printf("Maior area: %s\n", nome1);
    else if (area2 > area1)
        printf("Maior area: %s\n", nome2);
    else
        printf("Empate em area\n");

    // PIB
    if (PIB1 > PIB2)
        printf("Maior PIB: %s\n", nome1);
    else if (PIB2 > PIB1)
        printf("Maior PIB: %s\n", nome2);
    else
        printf("Empate em PIB\n");

    // Pontos turísticos
    if (pontos_turisticos1 > pontos_turisticos2)
        printf("Mais pontos turisticos: %s\n", nome1);
    else if (pontos_turisticos2 > pontos_turisticos1)
        printf("Mais pontos turisticos: %s\n", nome2);
    else
        printf("Empate em pontos turisticos\n");

    // PIB per capita
    if (PPC1 > PPC2)
        printf("Maior PIB per capita: %s\n", nome1);
    else if (PPC2 > PPC1)
        printf("Maior PIB per capita: %s\n", nome2);
    else
        printf("Empate em PIB per capita\n");

    // Densidade (menor vence)
    if (Densi1 < Densi2)
        printf("Menor densidade: %s\n", nome1);
    else if (Densi2 < Densi1)
        printf("Menor densidade: %s\n", nome2);
    else
        printf("Empate em densidade\n");

    return 0;
}