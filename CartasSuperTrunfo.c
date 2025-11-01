#include <stdio.h>
#include <string.h>

// Definições de constantes e mapeamento de atributos
#define MAX_CODIGO 5
#define MAX_NOME 50
#define NUM_ATRIBUTOS 5 // Populacao, Area, PIB, Pontos Turisticos, Densidade

// Mapeamento de texto para as opções do menu
const char *NOME_ATRIBUTOS[] = {
    "Nenhum (0)",
    "Populacao (1)",
    "Area (km²) (2)",
    "PIB (bilhoes de reais) (3)",
    "Pontos Turisticos (4)",
    "Densidade Demografica (hab/km²) (5)"
};

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
    float densidade_demografica; // Atributo calculado
} Carta;

// ----------------------------------------------------------------------
// FUNÇÕES AUXILIARES DE CONFIABILIDADE E CÁLCULO
// ----------------------------------------------------------------------

// Limpa o buffer de entrada (crucial para evitar vazamento de input)
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Calcula a Densidade Demografica
float calcular_densidade(int pop, float area) {
    // Retorna 0.0f se a area for zero para evitar divisao por zero
    return (area > 0) ? (float)pop / area : 0.0f; // Uso do Operador Ternário
}

// Obtem o valor do atributo da carta com base na escolha (para facilitar a soma)
float obter_valor_atributo(const Carta *carta, int escolha) {
    switch (escolha) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area_km2;
        case 3: return carta->pib_bilhoes;
        case 4: return (float)carta->pontos_turisticos;
        case 5: return carta->densidade_demografica;
        default: return 0.0f;
    }
}

// ----------------------------------------------------------------------
// FUNÇÕES DE INTERAÇÃO (MENUS DINÂMICOS)
// ----------------------------------------------------------------------

// Exibe o menu dinâmico
void exibir_menu_dinamico(int atributo_ignorado) {
    printf("\nEscolha o atributo (1 a %d):\n", NUM_ATRIBUTOS);
    for (int i = 1; i <= NUM_ATRIBUTOS; i++) {
        // Logica dinamica: ignora a opcao ja escolhida
        if (i != atributo_ignorado) {
            printf("%d. %s\n", i, NOME_ATRIBUTOS[i]);
        }
    }
    printf("Sua escolha: ");
}

// Obtem uma escolha valida do menu (Confiabilidade)
int obter_escolha_valida(int atributo_ignorado) {
    int escolha;
    int valido = 0;
    
    // Loop simples para leitura (simplificacao: a complexidade esta no switch/if-else)
    while (!valido) {
        exibir_menu_dinamico(atributo_ignorado);
        
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        if (escolha >= 1 && escolha <= NUM_ATRIBUTOS && escolha != atributo_ignorado) {
            valido = 1;
        } else if (escolha == atributo_ignorado) {
            printf("ATENCAO: Este atributo ja foi escolhido. Selecione outro.\n");
        } else {
            printf("Opcao inexistente. Escolha um numero de 1 a %d.\n", NUM_ATRIBUTOS);
        }
    }
    return escolha;
}


// ----------------------------------------------------------------------
// FUNÇÃO PRINCIPAL
// ----------------------------------------------------------------------
int main() {
    // Variaveis de controle e cartas
    Carta carta1, carta2;
    int escolha1, escolha2;
    float valor1_c1, valor2_c1, valor1_c2, valor2_c2;
    float soma_c1, soma_c2;

    // ====================================================================
    // 1. FASE DE CADASTRO (UNIFICADO DO NÍVEL NOVATO)
    // ====================================================================
    
    printf("====================================================\n");
    printf("        FASE 1: CADASTRO DE CARTAS\n");
    printf("====================================================\n\n");
    
    // --- Lógica simplificada de cadastro (Manutenibilidade) ---
    for (int i = 1; i <= 2; i++) {
        Carta *c = (i == 1) ? &carta1 : &carta2;
        printf("--- Insira os dados da CARTA %d ---\n", i);

        printf("1. Estado (APENAS UMA letra de 'A' a 'H'): ");
        scanf(" %c", &c->estado); 
        limpar_buffer(); 

        printf("2. Codigo da Carta (Ex: A01, B03): ");
        scanf("%s", c->codigo); 
        limpar_buffer(); 

        printf("3. Nome da Cidade: ");
        fgets(c->nome_cidade, MAX_NOME, stdin);
        c->nome_cidade[strcspn(c->nome_cidade, "\n")] = 0;
        
        printf("4. Populacao (int): ");
        scanf("%d", &c->populacao); limpar_buffer();

        printf("5. Area (em km2 - float): ");
        scanf("%f", &c->area_km2); limpar_buffer();

        printf("6. PIB (em bilhoes de reais - float): ");
        scanf("%f", &c->pib_bilhoes); limpar_buffer();

        printf("7. Pontos Turisticos (int): ");
        scanf("%d", &c->pontos_turisticos); limpar_buffer();
    }
    
    // --- Cálculo de Atributo ---
    carta1.densidade_demografica = calcular_densidade(carta1.populacao, carta1.area_km2);
    carta2.densidade_demografica = calcular_densidade(carta2.populacao, carta2.area_km2);


    // ====================================================================
    // 2. FASE DE COMPARAÇÃO AVANÇADA (NÍVEL MESTRE)
    // ====================================================================
    
    printf("\n\n====================================================\n");
    printf("        FASE 2: COMPARAÇÃO MULTI-ATRIBUTOS\n");
    printf("====================================================\n");

    // --- Escolha do Primeiro Atributo ---
    printf("\n>>> ESCOLHA DO PRIMEIRO ATRIBUTO <<<\n");
    escolha1 = obter_escolha_valida(0); // 0 = Nenhum atributo ignorado

    // --- Escolha do Segundo Atributo (Dinâmico) ---
    printf("\n>>> ESCOLHA DO SEGUNDO ATRIBUTO <<<\n");
    escolha2 = obter_escolha_valida(escolha1); // Ignora a primeira escolha

    // --- Obtenção dos Valores e Soma ---
    valor1_c1 = obter_valor_atributo(&carta1, escolha1);
    valor2_c1 = obter_valor_atributo(&carta1, escolha2);
    valor1_c2 = obter_valor_atributo(&carta2, escolha1);
    valor2_c2 = obter_valor_atributo(&carta2, escolha2);

    // Soma dos atributos (Requisito Funcional)
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    // --- Exibição e Resultado Final (Requisito Funcional) ---
    printf("\n====================================================\n");
    printf("        RESULTADO FINAL DA RODADA\n");
    printf("====================================================\n");
    
    printf("Carta 1 (%s) | Atributo 1 (%s): %.2f | Atributo 2 (%s): %.2f\n", 
           carta1.nome_cidade, NOME_ATRIBUTOS[escolha1], valor1_c1, NOME_ATRIBUTOS[escolha2], valor2_c1);
    printf("Carta 2 (%s) | Atributo 1 (%s): %.2f | Atributo 2 (%s): %.2f\n", 
           carta2.nome_cidade, NOME_ATRIBUTOS[escolha1], valor1_c2, NOME_ATRIBUTOS[escolha2], valor2_c2);
    
    printf("\nSoma dos Atributos:\n");
    printf("Soma %s: %.2f\n", carta1.nome_cidade, soma_c1);
    printf("Soma %s: %.2f\n", carta2.nome_cidade, soma_c2);

    // --- Decisão Final (Regras: Maior Soma Vence / Empate) ---
    printf("\n--- VENCEDOR DA RODADA ---\n");
    if (soma_c1 > soma_c2) {
        printf("A Carta 1 (%s) VENCEU com a soma de %.2f!\n", carta1.nome_cidade, soma_c1);
    } else if (soma_c2 > soma_c1) {
        printf("A Carta 2 (%s) VENCEU com a soma de %.2f!\n", carta2.nome_cidade, soma_c2);
    } else {
        printf("EMPATE! As cartas somaram o mesmo valor (%.2f).\n", soma_c1);
    }
    printf("====================================================\n");

    return 0;
}