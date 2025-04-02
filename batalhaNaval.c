#include <stdio.h>

int main() {
    int tabuleiro[10][10]; // Matriz 10x10 representando o tabuleiro
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Representação dos navios com vetor unidimensional
    int navio_horizontal[3] = {3, 3, 3}; // Horizontal
    int navio_vertical[3] = {3, 3, 3};   // Vertical

    // Coordenadas iniciais dos navios
    int linha_h = 2, coluna_h = 4; // Navio horizontal começa na linha 2, coluna 4
    int linha_v = 5, coluna_v = 7; // Navio vertical começa na linha 5, coluna 7

    // Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_h + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                printf("Erro: sobreposição no navio horizontal.\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
        }
    } else {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linha_v + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                printf("Erro: sobreposição no navio vertical.\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
        }
    } else {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
