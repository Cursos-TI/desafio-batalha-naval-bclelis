#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navio[3] = {3, 3, 3}; // Todos os navios são iguais
    int sucesso = 1;

    // ---- NAVIO 1: horizontal (linha 1, coluna 2 até 4) ----
    int linha1 = 1, coluna1 = 2;
    if (coluna1 + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha1][coluna1 + i] != 0) sucesso = 0;
        }
        if (sucesso) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha1][coluna1 + i] = navio[i];
            }
        } else {
            printf("Erro: sobreposição no navio 1.\n");
            return 1;
        }
    } else {
        printf("Erro: navio 1 fora do tabuleiro.\n");
        return 1;
    }

    sucesso = 1;

    // ---- NAVIO 2: vertical (linha 5 até 7, coluna 8) ----
    int linha2 = 5, coluna2 = 8;
    if (linha2 + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha2 + i][coluna2] != 0) sucesso = 0;
        }
        if (sucesso) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha2 + i][coluna2] = navio[i];
            }
        } else {
            printf("Erro: sobreposição no navio 2.\n");
            return 1;
        }
    } else {
        printf("Erro: navio 2 fora do tabuleiro.\n");
        return 1;
    }

    sucesso = 1;

    // ---- NAVIO 3: diagonal ↘ (linha 0, coluna 0 até 2) ----
    int linha3 = 0, coluna3 = 0;
    if (linha3 + 3 <= 10 && coluna3 + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha3 + i][coluna3 + i] != 0) sucesso = 0;
        }
        if (sucesso) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha3 + i][coluna3 + i] = navio[i];
            }
        } else {
            printf("Erro: sobreposição no navio 3.\n");
            return 1;
        }
    } else {
        printf("Erro: navio 3 fora do tabuleiro.\n");
        return 1;
    }

    sucesso = 1;

    // ---- NAVIO 4: diagonal ↙ (linha 2, coluna 7 até 5) ----
    int linha4 = 2, coluna4 = 7;
    if (linha4 + 3 <= 10 && coluna4 - 2 >= 0) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha4 + i][coluna4 - i] != 0) sucesso = 0;
        }
        if (sucesso) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha4 + i][coluna4 - i] = navio[i];
            }
        } else {
            printf("Erro: sobreposição no navio 4.\n");
            return 1;
        }
    } else {
        printf("Erro: navio 4 fora do tabuleiro.\n");
        return 1;
    }

    // ---- EXIBE O TABULEIRO ----
    printf("\nTabuleiro:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
