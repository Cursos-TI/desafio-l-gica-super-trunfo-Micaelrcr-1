#include <stdio.h>

int main()
{
    // Dados fixos reais aproximados de BR e EUA.
    int PopulacaoBR = 203080756, PopulacaoEUA = 331900000;
    int PontosTBR = 95, PontosTEUA = 120;
    double AreaBR = 8515767.0, AreaEUA = 9833520.0;
    double PIBBR = 2170.0, PIBEUA = 27360.0;
    double DensiBR, DensiEUA;
    int resultado1, resultado2;
    int atributo1, atributo2;
    int placar = 0;
    int opcoes[5] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    int escolha;

    // Densidade demográfica = população / área.
    DensiBR = PopulacaoBR / AreaBR;
    DensiEUA = PopulacaoEUA / AreaEUA;

    // Primeiro menu: lista todos os atributos disponíveis.
    printf("Escolha o primeiro atributo:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d. ", i + 1);
        switch (opcoes[i]) {
            case 1: printf("População\n"); break;
            case 2: printf("Área\n"); break;
            case 3: printf("PIB\n"); break;
            case 4: printf("Pontos Turísticos\n"); break;
            case 5: printf("Densidade Demográfica\n"); break;
        }
    }

    if (scanf("%d", &escolha) != 1) {
        printf("Entrada inválida!\n");
        return 1;
    }

    if (escolha < 1 || escolha > tamanho) {
        printf("Opção inválida!\n");
        return 1;
    }

    int atributo1_index = escolha - 1;
    atributo1 = opcoes[atributo1_index];

    // Remove o atributo já escolhido para criar um segundo menu dinâmico.
    for (int i = atributo1_index; i < tamanho - 1; i++) {
        opcoes[i] = opcoes[i + 1];
    }
    tamanho--;

    // Segundo menu: agora sem repetir o atributo anterior.
    printf("\nEscolha o segundo atributo:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d. ", i + 1);
        switch (opcoes[i]) {
            case 1: printf("População\n"); break;
            case 2: printf("Área\n"); break;
            case 3: printf("PIB\n"); break;
            case 4: printf("Pontos Turísticos\n"); break;
            case 5: printf("Densidade Demográfica\n"); break;
        }
    }

    if (scanf("%d", &escolha) != 1) {
        printf("Entrada inválida!\n");
        return 1;
    }

    if (escolha < 1 || escolha > tamanho) {
        printf("Opção inválida!\n");
        return 1;
    }

    atributo2 = opcoes[escolha - 1];

    // Regras: maior valor vence, exceto densidade (menor vence). Empate vale 0.
    switch (atributo1) {
        case 1: resultado1 = (PopulacaoBR > PopulacaoEUA) ? 1 : (PopulacaoBR < PopulacaoEUA ? -1 : 0); break;
        case 2: resultado1 = (AreaBR > AreaEUA) ? 1 : (AreaBR < AreaEUA ? -1 : 0); break;
        case 3: resultado1 = (PIBBR > PIBEUA) ? 1 : (PIBBR < PIBEUA ? -1 : 0); break;
        case 4: resultado1 = (PontosTBR > PontosTEUA) ? 1 : (PontosTBR < PontosTEUA ? -1 : 0); break;
        case 5: resultado1 = (DensiBR < DensiEUA) ? 1 : (DensiBR > DensiEUA ? -1 : 0); break;
        default: return 1;
    }

    switch (atributo2) {
        case 1: resultado2 = (PopulacaoBR > PopulacaoEUA) ? 1 : (PopulacaoBR < PopulacaoEUA ? -1 : 0); break;
        case 2: resultado2 = (AreaBR > AreaEUA) ? 1 : (AreaBR < AreaEUA ? -1 : 0); break;
        case 3: resultado2 = (PIBBR > PIBEUA) ? 1 : (PIBBR < PIBEUA ? -1 : 0); break;
        case 4: resultado2 = (PontosTBR > PontosTEUA) ? 1 : (PontosTBR < PontosTEUA ? -1 : 0); break;
        case 5: resultado2 = (DensiBR < DensiEUA) ? 1 : (DensiBR > DensiEUA ? -1 : 0); break;
        default: return 1;
    }

    printf("\nComparação:\n");

    switch (atributo1) {
        case 1: printf("População: BR %d x EUA %d\n", PopulacaoBR, PopulacaoEUA); break;
        case 2: printf("Área: BR %.0f x EUA %.0f\n", AreaBR, AreaEUA); break;
        case 3: printf("PIB: BR %.0f x EUA %.0f\n", PIBBR, PIBEUA); break;
        case 4: printf("Pontos Turísticos: BR %d x EUA %d\n", PontosTBR, PontosTEUA); break;
        case 5: printf("Densidade: BR %.2f x EUA %.2f\n", DensiBR, DensiEUA); break;
    }

    switch (atributo2) {
        case 1: printf("População: BR %d x EUA %d\n", PopulacaoBR, PopulacaoEUA); break;
        case 2: printf("Área: BR %.0f x EUA %.0f\n", AreaBR, AreaEUA); break;
        case 3: printf("PIB: BR %.0f x EUA %.0f\n", PIBBR, PIBEUA); break;
        case 4: printf("Pontos Turísticos: BR %d x EUA %d\n", PontosTBR, PontosTEUA); break;
        case 5: printf("Densidade: BR %.2f x EUA %.2f\n", DensiBR, DensiEUA); break;
    }

    placar += resultado1;
    placar += resultado2;

    printf("\nResultado final:\n");
    if (placar > 0) printf("Brasil venceu\n");
    else if (placar < 0) printf("Estados Unidos venceu\n");
    else printf("Empate\n");

    return 0;
}