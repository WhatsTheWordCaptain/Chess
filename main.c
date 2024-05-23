#include <stdio.h>

typedef struct {
    char board[8][8];
} Board;

void checkThreat(Board board) {
    for (int i = 0; i < 8; i++) { // Check for threat from rook
        for (int j = 0; j < 8; j++) {
            if (board.board[i][j] == 'b') {
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 && l == 0) continue;
                        int ni = i + k;
                        int nj = j + l;
                        while (ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
                            if (board.board[ni][nj] == 'K') {
                                printf("Threat from Rook.\n");
                                return;
                            }
                            if (board.board[ni][nj] != '.') {
                                break;
                            }
                            ni += k;
                            nj += l;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) { // Check for threat from bishop
        for (int j = 0; j < 8; j++) {
            if (board.board[i][j] == 's') {
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 && l == 0) continue;
                        int ni = i + k;
                        int nj = j + l;
                        while (ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
                            if (board.board[ni][nj] == 'K') {
                                printf("Threat from Bishop.\n");
                                return;
                            }
                            if (board.board[ni][nj] != '.') {
                                break;
                            }
                            ni += k;
                            nj += l;
                        }
                    }
                }
            }
        }
    }

    printf("No threat found.\n"); // In case there is no threat
}

int main() {
    Board board;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board.board[i][j] = '.';
        }
    }

    int blackRookRow, blackRookCol;
    printf("Enter the row and column for the rook: ");
    scanf("%d %d", &blackRookRow, &blackRookCol);
    board.board[blackRookRow][blackRookCol] = 'b';
    int bishopRow, bishopCol;
    
    printf("Enter the row and column for the bishop: ");
    scanf("%d %d", &bishopRow, &bishopCol);
    board.board[bishopRow][bishopCol] = 's';

    int kingRow, kingCol;
    printf("Enter the row and column for the king: ");
    scanf("%d %d", &kingRow, &kingCol);
    board.board[kingRow][kingCol] = 'K';

    checkThreat(board);

    return 0;
}
