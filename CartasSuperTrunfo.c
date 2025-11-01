#include <stdio.h>
#include <string.h>

// Definição de constantes para o tamanho máximo das strings, 
// o que aumenta a legibilidade e a segurança (evita 'magic numbers').
#define MAX_CODIGO 4    // Ex: A01 (3 caracteres + \0)
#define MAX_NOME 50     // Tamanho suficiente para o nome da cidade

int main() {
    // --- Variáveis para a CARTA 1 ---
    // Nomes de variáveis são claros e descritivos.
    char estado_carta1;
    char codigo_carta1[MAX_CODIGO]; 
    char nome_cidade1[MAX_NOME];
    int populacao1;
    float area_km2_1;
    float pib_bilhoes_1;
    int pontos_turisticos1;

    // --- Variáveis para a CARTA 2 ---
    char estado_carta2;
    char codigo_carta2[MAX_CODIGO];
    char nome_cidade2[MAX_NOME];
    int populacao2;
    float area_km2_2; 
    float pib_bilhoes_2;
    int pontos_turisticos2;

    // Cabeçalho claro (Requisito: Usabilidade)
    printf("====================================================\n");
    printf("        CADASTRO DE CARTAS - SUPER TRUNFO\n");
    printf("====================================================\n\n");
    
    // ----------------------------------------------------------------------
    // --- LEITURA DE DADOS PARA A CARTA 1 ---
    // ----------------------------------------------------------------------
    printf("--- Por favor, insira os dados da CARTA 1 ---\n");
    
    // Instruções claras para cada campo (Requisito: Usabilidade)
    printf("1. Estado (Uma letra de 'A' a 'H'): ");
    // O espaco antes de %c ajuda a limpar o buffer (Corretude)
    scanf(" %c", &estado_carta1); 

    printf("2. Codigo da Carta (Ex: A01, B03): ");
    scanf("%s", codigo_carta1); 

    printf("3. Nome da Cidade: ");
    // Usamos getchar() para limpar o buffer de entrada
    getchar(); 
    // fgets() é mais seguro para ler nomes com espacos
    fgets(nome_cidade1, MAX_NOME, stdin);
    // Remove o caractere de nova linha que fgets() adiciona
    nome_cidade1[strcspn(nome_cidade1, "\n")] = 0;
    
    printf("4. Populacao (numero de habitantes - int): ");
    scanf("%d", &populacao1);

    printf("5. Area (em km2 - float): ");
    scanf("%f", &area_km2_1);

    printf("6. PIB (em bilhoes de reais - float): ");
    scanf("%f", &pib_bilhoes_1);

    printf("7. Numero de Pontos Turisticos (int): ");
    scanf("%d", &pontos_turisticos1);

    // ----------------------------------------------------------------------
    // --- LEITURA DE DADOS PARA A CARTA 2 ---
    // ----------------------------------------------------------------------
    printf("\n----------------------------------------------------\n");
    printf("--- Por favor, insira os dados da CARTA 2 ---\n");

    printf("1. Estado (Uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado_carta2); 

    printf("2. Codigo da Carta (Ex: B02, C04): ");
    scanf("%s", codigo_carta2); 

    printf("3. Nome da Cidade: ");
    getchar(); // Limpa o buffer
    fgets(nome_cidade2, MAX_NOME, stdin);
    // Remove o caractere de nova linha
    nome_cidade2[strcspn(nome_cidade2, "\n")] = 0;
    
    printf("4. Populacao (numero de habitantes - int): ");
    scanf("%d", &populacao2);

    printf("5. Area (em km2 - float): ");
    scanf("%f", &area_km2_2);

    printf("6. PIB (em bilhoes de reais - float): ");
    scanf("%f", &pib_bilhoes_2);

    printf("7. Numero de Pontos Turisticos (int): ");
    scanf("%d", &pontos_turisticos2);

    // ----------------------------------------------------------------------
    // --- EXIBIÇÃO DE DADOS (Organizada e Legível) ---
    // ----------------------------------------------------------------------
    printf("\n====================================================\n");
    printf("        RELATÓRIO DE CARTAS CADASTRADAS\n");
    printf("====================================================\n");

    // Exibição da Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado_carta1);
    printf("Codigo: %s\n", codigo_carta1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("Populacao: %d\n", populacao1);
    // Formatação de float com duas casas decimais
    printf("Area: %.2f km²\n", area_km2_1); 
    printf("PIB: %.2f bilhoes de reais\n", pib_bilhoes_1);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos1);

    // Exibição da Carta 2
    printf("\n----------------------------------------------------\n");
    printf("Carta 2:\n");
    printf("Estado: %c\n",