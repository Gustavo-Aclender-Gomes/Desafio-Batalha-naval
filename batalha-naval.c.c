#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 5
#define TOTAL_NAVIOS 3

typedef struct {
    int x;
    int y;
} Coordenada;

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void mostrarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
int jogar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Coordenada navios[TOTAL_NAVIOS]);
int verificarAcerto(Coordenada tiro, Coordenada navios[TOTAL_NAVIOS]);

int main() {
    char tabuleiroJogador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    Coordenada naviosJogador[TOTAL_NAVIOS];
    srand(time(NULL));

    inicializarTabuleiro(tabuleiroJogador);
    
    // Coloca navios aleatoriamente
    for (int i = 0; i < TOTAL_NAVIOS; i++) {
        naviosJogador[i].x = rand() % TAMANHO_TABULEIRO;
        naviosJogador[i].y = rand() % TAMANHO_TABULEIRO;
    }

    printf("Jogo Batalha Naval!\n");

    int acertos = 0;
    while (acertos < TOTAL_NAVIOS) {
        mostrarTabuleiro(tabuleiroJogador);

        Coordenada tiro;
        printf("Informe a coordenada do tiro (linha e coluna): ");
        scanf("%d %d", &tiro.x, &tiro.y);

        if (tiro.x < 0 || tiro.x >= TAMANHO_TABULEIRO || tiro.y < 0 || tiro.y >= TAMANHO_TABULEIRO) {
            printf("Coordenada inválida. Tente novamente.\n");
            continue;
        }

        if (verificarAcerto(tiro, naviosJogador)) {
            tabuleiroJogador[tiro.x][tiro.y] = 'X';
            printf("Acertou um navio!\n");
            acertos++;
        } else {
            tabuleiroJogador[tiro.x][tiro.y] = 'O';
            printf("Errou! Tente novamente.\n");
        }
    }

    printf("Parabéns! Você afundou todos os navios!\n");

    return 0;
}

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '~';  // Representa água
        }
    }
}

void mostrarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha:\n");
    printf("   0 1 2 3 4\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int verificarAcerto(Coordenada tiro, Coordenada navios[TOTAL_NAVIOS]) {
    for (int i = 0; i < TOTAL_NAVIOS; i++) {
        if (tiro.x == navios[i].x && tiro.y == navios[i].y) {
            return 1; // Acerto
        }
    }
    return 0; // Erro
}
