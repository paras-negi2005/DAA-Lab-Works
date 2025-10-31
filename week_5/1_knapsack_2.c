#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Brute Force Recursive Knapsack function
int knapsack(int W, int wt[], int val[], int n) {
    // Base case: no items or no capacity
    if (n == 0 || W == 0)
        return 0;

    // If weight of nth item is more than capacity, skip it
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Otherwise, return max of two cases:
    // (1) Include the item
    // (2) Exclude the item
    else
        return max(
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
            knapsack(W, wt, val, n - 1)
        );
}

int main() {
    int val[] = {60, 120, 100};
    int wt[]  = {10, 30, 20};
    int W = 50;
    int n = 3;

    int result = knapsack(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", result);

    return 0;
}
