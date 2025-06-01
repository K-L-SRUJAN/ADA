#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int leftArr[n1], rightArr[n2];
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000 + 1;
    }
}

double measureTime(int n) {
    int arr[n];
    generateArray(arr, n);

    clock_t start_time = clock();

    mergeSort(arr, 0, n - 1);

    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    return time_taken;
}

int main() {
    int si;
    printf("Enter the number test cases to be runed : ");
    scanf("%d", &si);
    printf("\nNow you should enter the each test case make sure you increase the input size expoentially");
    int N_values[si];
    for(int i = 0; i < si; i++) {
        printf("\nEnter the case size : ");
        int y;
        scanf("%d", &y);
        N_values[i] = y;
    }
    int num_tests = sizeof(N_values) / sizeof(N_values[0]);
    
    for (int i = 0; i < num_tests; i++) {
        int N = N_values[i];
        double time_taken = measureTime(N);
        printf("Time taken to sort %d elements: %.6f seconds\n", N, time_taken);
    }

    return 0;
}
