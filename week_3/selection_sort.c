#include <stdio.h>

void selectionSort(int a[], int n) {
    int i, j, loc, temp;

    for (i = 0; i < n - 1; i++) {
        loc = i;  // assume min element is at position i

        // find the position of the minimum element
        for (j = i + 1; j < n; j++) {
            if (a[loc] > a[j]) {
                loc = j;
            }
        }

        // if new min found, swap
        if (loc != i) {
            temp = a[loc];
            a[loc] = a[i];
            a[i] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {28, 43, 51, 41, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}
