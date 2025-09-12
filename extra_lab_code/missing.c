#include <stdio.h>

int findMissing(int arr[], int n) {
    int total = n * (n + 1) / 2;  // expected sum 1..n
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {  // array has n-1 elements
        sum += arr[i];
    }
    return total - sum;
}

int main() {
    int n;
    printf("Enter the end range (from 1 to n): ");
    scanf("%d", &n);

    int arr[n-1];  // array has n-1 elements (one missing)

    printf("Enter %d elements (from 1 to %d, one missing):\n", n-1, n);
    for (int i = 0; i < n-1; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = findMissing(arr, n);
    printf("Missing number is: %d\n", missing);

    return 0;
}