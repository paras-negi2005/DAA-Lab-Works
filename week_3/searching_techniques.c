#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------- Linear Search ----------
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // element found
        }
    }
    return -1; // not found
}

// ---------- Binary Search ----------
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid; // element found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000}; 
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    int repeat = 1000;  // repeat searches to get measurable times

    printf("N\tLinearSearch(time)\tBinarySearch(time)\n");
    printf("-------------------------------------------------\n");

    for (int t = 0; t < numSizes; t++) {
        int n = sizes[t];
        int *arr = (int *)malloc(n * sizeof(int));

        // Fill sorted array (1 to n)
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int key = n; // search for last element (worst case for linear)

        // ---------- Linear Search ----------
        clock_t start = clock();
        for (int r = 0; r < repeat; r++) {
            linearSearch(arr, n, key);
        }
        clock_t end = clock();
        double timeLinear = (double)(end - start) / CLOCKS_PER_SEC;

        // ---------- Binary Search ----------
        start = clock();
        for (int r = 0; r < repeat; r++) {
            binarySearch(arr, n, key);
        }
        end = clock();
        double timeBinary = (double)(end - start) / CLOCKS_PER_SEC;

        // Print results
        printf("%d\t%.6f s\t\t%.6f s\n", n, timeLinear, timeBinary);

        free(arr);
    }

    return 0;
}
