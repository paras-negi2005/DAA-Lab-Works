#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------- Bubble Sort ----------
void bubbleSort(int arr[], int n, long long *swapCount) {
    *swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++;
                swapped = 1;
            }
        }
        if (!swapped) break; // already sorted
    }
}

// ---------- Selection Sort ----------
void selectionSort(int arr[], int n, long long *swapCount) {
    *swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            (*swapCount)++;
        }
    }
}

// ---------- Insertion Sort ----------
void insertionSort(int arr[], int n, long long *swapCount) {
    *swapCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            (*swapCount)++;
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------- Main ----------
int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL)); // randomize seed

    printf("N\t   BubbleSort(time, swaps)\t   SelectionSort(time, swaps)\t   InsertionSort(time, swaps)\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    for (int t = 0; t < numTests; t++) {
        int n = sizes[t];
        int *arr = (int *)malloc(n * sizeof(int));

        // generate random array
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;
        }

        // -------- Bubble Sort --------
        int *arrCopy = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arrCopy[i] = arr[i];
        long long swapsBubble = 0;
        clock_t start = clock();
        bubbleSort(arrCopy, n, &swapsBubble);
        clock_t end = clock();
        double timeBubble = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arrCopy);

        // -------- Selection Sort --------
        arrCopy = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arrCopy[i] = arr[i];
        long long swapsSelection = 0;
        start = clock();
        selectionSort(arrCopy, n, &swapsSelection);
        end = clock();
        double timeSelection = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arrCopy);

        // -------- Insertion Sort --------
        arrCopy = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arrCopy[i] = arr[i];
        long long swapsInsertion = 0;
        start = clock();
        insertionSort(arrCopy, n, &swapsInsertion);
        end = clock();
        double timeInsertion = ((double)(end - start)) / CLOCKS_PER_SEC;
        free(arrCopy);

        // print results
        printf("%-8d %-10.5f %12lld\t %-10.5f %12lld\t %-10.5f %12lld\n",
               n, timeBubble, swapsBubble,
               timeSelection, swapsSelection,
               timeInsertion, swapsInsertion);

        free(arr);
    }

    return 0;
}
