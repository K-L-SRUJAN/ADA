#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_largest_mobile(int *perm, int *dir, int n) {
    int largest = -1, index = -1;
    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i > 0 && perm[i] > perm[i - 1]) {
            if (perm[i] > largest) {
                largest = perm[i];
                index = i;
            }
        }
        if (dir[i] == RIGHT && i < n - 1 && perm[i] > perm[i + 1]) {
            if (perm[i] > largest) {
                largest = perm[i];
                index = i;
            }
        }
    }
    return index;
}

void reverse_direction(int *dir, int *perm, int largest, int n) {
    for (int i = 0; i < n; i++) {
        if (perm[i] > largest) {
            dir[i] = -dir[i];
        }
    }
}

void generate_permutations(int n) {
    int *perm = (int*)malloc(n * sizeof(int));
    int *dir = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");

    while (1) {
        int index = find_largest_mobile(perm, dir, n);
        if (index == -1)
            break;

        int swap_index = index + dir[index];
        swap(&perm[index], &perm[swap_index]);
        swap(&dir[index], &dir[swap_index]);

        reverse_direction(dir, perm[swap_index], n, n);

        for (int i = 0; i < n; i++)
            printf("%d ", perm[i]);
        printf("\n");
    }

    free(perm);
    free(dir);
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    generate_permutations(n);

    return 0;
}
