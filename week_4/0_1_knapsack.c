#include <stdio.h>

// Function to sort arrays by profit in descending order
void sortByProfit(int n, int profit[], int weight[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profit[i] < profit[j]) {
                // Swap profit
                int tempProfit = profit[i];
                profit[i] = profit[j];
                profit[j] = tempProfit;

                // Swap weight to keep them paired
                int tempWeight = weight[i];
                weight[i] = weight[j];
                weight[j] = tempWeight;
            }
        }
    }
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by profit in descending order
    sortByProfit(n, profit, weight);

    int totalProfit = 0;
    int remainingCapacity = capacity;

    printf("\nItems selected:\n");
    for (int i = 0; i < n; i++) {
        if (weight[i] <= remainingCapacity) {
            printf("Item %d: Profit = %d, Weight = %d\n", i + 1, profit[i], weight[i]);
            totalProfit += profit[i];
            remainingCapacity -= weight[i];
        }
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}
