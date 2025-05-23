#include <stdio.h>
#include <stdlib.h>

int is_safe(int** board, int row, int col, int n) {
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return 0;

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;

    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

void print_board(int** board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

int solve_n_queens_util(int** board, int row, int n) {
    if (row == n) {
        print_board(board, n);
        return 1;
    }

    int res = 0;
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            board[row][col] = 1;
            res = solve_n_queens_util(board, row + 1, n) || res;
            board[row][col] = 0;
        }
    }
    return res;
}

void solve_n_queens(int n) {
    int** board = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        board[i] = (int*)calloc(n, sizeof(int));
    }

    if (!solve_n_queens_util(board, 0, n)) {
        printf("No solution exists for N = %d\n", n);
    }

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);
}

int main() {
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    solve_n_queens(n);

    return 0;
}
