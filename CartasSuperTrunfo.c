#include <stdio.h>
#include <string.h>

// Definições de constantes (Legibilidade e Manutenibilidade)
#define MAX_CODIGO 5
#define MAX_NOME 50

// ----------------------------------------------------------------------
// ESTRUTURA PARA REPRESENTAR UMA CARTA
// ----------------------------------------------------------------------
typedef struct {
    char estado;
    char codigo[MAX_CODIGO];
    char nome_cidade[MAX_NOME];
    int populacao;
    float area_km2;
    float pib_bilhoes;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// ----------------------------------------------------------------------
// FUNÇÕES AUXILIARES
// ----------------------------------------------------------------------

// Calcula a Densidade Demografica
float calcular_densidade(int pop, float area) {
    if (area > 0) {
        return (float)pop / area;
    }
    return 0.0f;
}

// Limpa o buffer de entrada (crucial para evitar o bug do 'vazamento' de input)
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe o menu de comparacao (Usabilidade)
void exibir_menu() {
    printf("\n====================================================\n");
    printf("        SUPER TRUNFO - ESCOLHA O ATRIBUTO\n");
    printf("====================================================\n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1. Populacao\n");
    printf("2. Area (km²)\n");
    printf("3. PIB (bilhoes de reais)\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (habitantes/km²)\n");
    printf("----------------------------------------------------\n");
    printf("Sua escolha (1 a 5): ");
}

// ----------------------------------------------------------------------
// FUNÇÃO PRINCIPAL
// ----------------------------------------------------------------------
int main() {
    Carta carta1;
    Carta carta2;

    int escolha_atributo;
    char nome_atributo[50];
    float valor1 = 0.0f, valor2 = 0.0f;
    int resultado_comparacao = 0; // 1 = C1 Vence, 2 = C2 Vence, 0 = Empate

    // ====================================================================
    // 1. FASE DE CADASTRO (CORREÇÃO DE BUGS DE INPUT)
    // ====================================================================
    
    printf("====================================================\n");
    printf("        FASE 1: CADASTRO DE CARTAS\n");
    printf("====================================================\n\n");
    
    // --- CADASTRO DA CARTA 1 ---
    printf("--- Insira os dados da CARTA 1 ---\n");
    
    // CORREÇÃO 1: Usamos %[^\n] e limite de 1 caractere para ler apenas o primeiro char.
    printf("1. Estado (APENAS UMA letra de 'A' a 'H'): ");
    scanf(" %c", &carta1.estado); 
    // Limpa o buffer imediatamente, descartando o restante da linha digitada 
    // (Ex: se o usuario digitou "Rio de Janeiro" aqui, so 'R' sera lido).
    limpar_buffer(); 

    printf("2. Codigo da Carta (Ex: A01, B03): ");
    scanf("%s", carta1.codigo); 
    limpar_buffer(); // Limpa apos o scanf %s

    // CORREÇÃO 2: fgets para o nome da cidade.
    printf("3. Nome da Cidade: ");
    fgets(carta1.nome_cidade, MAX_NOME, stdin);
    carta1.nome_cidade[strcspn(carta1.nome_cidade, "\n")] = 0;
    
    printf("4. Populacao (numero de habitantes - int): ");
    if (scanf("%d", &carta1.populacao) != 1) { limpar_buffer(); }

    printf("5. Area (em km2 - float): ");
    if (scanf("%f", &carta1.area_km2) != 1) { limpar_buffer(); }

    printf("6. PIB (em bilhoes de reais - float): ");
    if (scanf("%f", &carta1.pib_bilhoes) != 1) { limpar_buffer(); }

    printf("7. Numero de Pontos Turisticos (int): ");
    if (scanf("%d", &carta1.pontos_turisticos) != 1) { limpar_buffer(); }
    limpar_buffer(); // Limpa no final do bloco.

    // --- CADASTRO DA CARTA 2 ---
    printf("\n----------------------------------------------------\n");
    printf("--- Insira os dados da CARTA 2 ---\n");

    printf("1. Estado (APENAS UMA letra de 'A' a 'H'): ");
    scanf(" %c", &carta2.estado); 
    limpar_buffer(); 

    printf("2. Codigo da Carta (Ex: B02, C04): ");
    scanf("%s", carta2.codigo); 
    limpar_buffer(); 

    printf("3. Nome da Cidade: ");
    fgets(carta2.nome_cidade, MAX_NOME, stdin);
    carta2.nome_cidade[strcspn(carta2.nome_cidade, "\n")] = 0;
    
    printf("4. Populacao (numero de habitantes - int): ");
    if (scanf("%d", &carta2.populacao) != 1) { limpar_buffer(); }

    printf("5. Area (em km2 - float): ");
    if (scanf("%f", &carta2.area_km2) != 1) { limpar_buffer(); }

    printf("6. PIB (em bilhoes de reais - float): ");
    if (scanf("%f", &carta2.pib_bilhoes) != 1) { limpar_buffer(); }

    printf("7. Numero de Pontos Turisticos (int): ");
    if (scanf("%d", &carta2.pontos_turisticos) != 1) { limpar_buffer(); }
    limpar_buffer(); 

    // --- CÁLCULO DE ATRIBUTO ---
    carta1.densidade_demografica = calcular_densidade(carta1.populacao, carta1.area_km2);
    carta2.densidade_demografica = calcular_densidade(carta2.populacao, carta2.area_km2);


    // ====================================================================
    // 2. FASE DE EXIBIÇÃO E INTERAÇÃO
    // ====================================================================
    
    printf("\n\n====================================================\n");
    printf("        RELATÓRIO E COMPARACAO\n");
    printf("====================================================\n");
    printf("\nCartas prontas para o jogo:\n");
    printf("1. %s (Codigo: %s)\n", carta1.nome_cidade, carta1.codigo);
    printf("2. %s (Codigo: %s)\n", carta2.nome_cidade, carta2.codigo);


    // --- Menu e Leitura da Escolha ---
    exibir_menu();
    if (scanf("%d", &escolha_atributo) != 1) { limpar_buffer(); }

    // --- Logica de Comparacao com SWITCH e IF-ELSE ---
    switch (escolha_atributo) {
        case 1: strcpy(nome_atributo, "Populacao"); valor1 = (float)carta1.populacao; valor2 = (float)carta2.populacao; 
            if (valor1 > valor2) { resultado_comparacao = 1; } else if (valor2 > valor1) { resultado_comparacao = 2; } break;
        case 2: strcpy(nome_atributo, "Area (km²)"); valor1 = carta1.area_km2; valor2 = carta2.area_km2;
            if (valor1 > valor2) { resultado_comparacao = 1; } else if (valor2 > valor1) { resultado_comparacao = 2; } break;
        case 3: strcpy(nome_atributo, "PIB (bilhoes de reais)"); valor1 = carta1.pib_bilhoes; valor2 = carta2.pib_bilhoes;
            if (valor1 > valor2) { resultado_comparacao = 1; } else if (valor2 > valor1) { resultado_comparacao = 2; } break;
        case 4: strcpy(nome_atributo, "Pontos Turisticos"); valor1 = (float)carta1.pontos_turisticos; valor2 = (float)carta2.pontos_turisticos;
            if (valor1 > valor2) { resultado_comparacao = 1; } else if (valor2 > valor1) { resultado_comparacao = 2; } break;
        case 5: // REGRA ESPECIAL: MENOR valor vence
            strcpy(nome_atributo, "Densidade Demografica (hab/km²)"); valor1 = carta1.densidade_demografica; valor2 = carta2.densidade_demografica;
            if (valor1 < valor2) { resultado_comparacao = 1; } else if (valor2 < valor1) { resultado_comparacao = 2; } break;
        default: strcpy(nome_atributo, "Opcao Invalida"); resultado_comparacao = -1; break;
    }

    // --- Exibição do Resultado Final ---
    printf("\n====================================================\n");
    
    if (resultado_comparacao == -1) {
        printf("ERRO: Escolha de atributo invalida. Reinicie o programa.\n");
    } else {
        printf("        RESULTADO DA RODADA\n");
        printf("====================================================\n");
        printf("Atributo: %s\n", nome_atributo);
        printf("Valor %s: %.2f\n", carta1.nome_cidade, valor1);
        printf("Valor %s: %.2f\n", carta2.nome_cidade, valor2);

        printf("\n--- VENCEDOR ---\n");
        if (resultado_comparacao == 1) {
            printf("A Carta 1 (%s) VENCEU!\n", carta1.nome_cidade);
        } else if (resultado_comparacao == 2) {
            printf("A Carta 2 (%s) VENCEU!\n", carta2.nome_cidade);
        } else {
            printf("EMPATE!\n");
        }
    }
    printf("====================================================\n");

    return 0;
}