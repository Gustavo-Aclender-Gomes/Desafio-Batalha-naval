#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define NAVIO 3
#define VAZIO 0

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

// Função para exibir o tabuleiro completo
void mostrarTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para posicionar navios na horizontal ou vertical
void posicionarNavioReto(int tabuleiro[TAM][TAM]) {
    int linha, coluna, orientacao;
    int tamanho = 3;

    do {
        linha = rand() % TAM;
        coluna = rand() % TAM;
        orientacao = rand() % 2; // 0 = horizontal, 1 = vertical

        int valido = 1;

        for (int i = 0; i < tamanho; i++) {
            int x = linha + (orientacao == 1 ? i : 0);
            int y = coluna + (orientacao == 0 ? i : 0);
            if (x >= TAM || y >= TAM || tabuleiro[x][y] != VAZIO) {
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (int i = 0; i < tamanho; i++) {
                int x = linha + (orientacao == 1 ? i : 0);
                int y = coluna + (orientacao == 0 ? i : 0);
                tabuleiro[x][y] = NAVIO;
            }
            break;
        }

    } while (1);
}

// Função para posicionar navios na diagonal
void posicionarNavioDiagonal(int tabuleiro[TAM][TAM]) {
    int linha, coluna, direcao;
    int tamanho = 3;

    do {
        linha = rand() % TAM;
        coluna = rand() % TAM;
        direcao = rand() % 2; // 0 = \ , 1 = /

        int valido = 1;

        for (int i = 0; i < tamanho; i++) {
            int x = linha + i;
            int y = (direcao == 0) ? (coluna + i) : (coluna - i);

            if (x >= TAM || y < 0 || y >= TAM || tabuleiro[x][y] != VAZIO) {
                valido = 0;
                break;
            }
        }

        if (valido) {
            for (int i = 0; i < tamanho; i++) {
                int x = linha + i;
                int y = (direcao == 0) ? (coluna + i) : (coluna - i);
                tabuleiro[x][y] = NAVIO;
            }
            break;
        }

    } while (1);
}

int main() {
    int tabuleiro[TAM][TAM];
    srand(time(NULL));

    inicializarTabuleiro(tabuleiro);

    // Posiciona 2 navios retos (horizontal ou vertical)
    posicionarNavioReto(tabuleiro);
    posicionarNavioReto(tabuleiro);

    // Posiciona 2 navios diagonais (\ ou /)
    posicionarNavioDiagonal(tabuleiro);
    posicionarNavioDiagonal(tabuleiro);

    // Mostra o tabuleiro completo com os navios
    mostrarTabuleiro(tabuleiro);

    return 0;
}
