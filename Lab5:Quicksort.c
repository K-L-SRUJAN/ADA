#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int tests, size;
    printf("Enter number of test cases: ");
    scanf("%d", &tests);

    srand(time(0));

    for (int t = 0; t < tests; t++) {
        printf("Enter array size for test %d: ", t + 1);
        scanf("%d", &size);

        int *arr = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000;
        }

        clock_t start = clock();
        quickSort(arr, 0, size - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Test %d: QuickSort took %f seconds\n", t + 1, time_taken);

        free(arr);
    }

    return 0;
}
