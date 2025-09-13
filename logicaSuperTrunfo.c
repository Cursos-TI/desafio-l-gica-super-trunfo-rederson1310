#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    long populacao;
    double area;
    double pib;
    int pontosTuristicos;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Digite o estado: ");
    fgets(carta->estado, 50, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0; // Remove o '\n'

    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigo);
    getchar(); // Limpar buffer

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 50, stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%ld", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%lf", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    getchar(); // Limpar buffer
}

// Função para exibir uma carta
void exibirCarta(Carta carta) {
    printf("\nCarta: %s (%s)\n", carta.nome, carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("População: %ld\n", carta.populacao);
    printf("Área: %.2lf km²\n", carta.area);
    printf("PIB: %.2lf bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
}

// Função para comparar cartas por um atributo
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("\nComparando cartas...\n");
    exibirCarta(c1);
    exibirCarta(c2);

    int vencedor = 0; // 1 -> c1 vence, 2 -> c2 vence

    switch (atributo) {
        case 1: // População
            vencedor = (c1.populacao > c2.populacao) ? 1 : 2;
            break;
        case 2: // Área
            vencedor = (c1.area > c2.area) ? 1 : 2;
            break;
        case 3: // PIB
            vencedor = (c1.pib > c2.pib) ? 1 : 2;
            break;
        case 4: // Pontos turísticos
            vencedor = (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 2;
            break;
        case 5: // Densidade populacional (menor vence)
            {
                double dens1 = c1.populacao / c1.area;
                double dens2 = c2.populacao / c2.area;
                vencedor = (dens1 < dens2) ? 1 : 2;
            }
            break;
        default:
            printf("Atributo inválido.\n");
            return;
    }

    printf("\nA carta vencedora é: %s (%s)\n",
           (vencedor == 1) ? c1.nome : c2.nome,
           (vencedor == 1) ? c1.estado : c2.estado);
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional\n");
    int atributo;
    scanf("%d", &atributo);

    compararCartas(carta1, carta2, atributo);

    return 0;
}
