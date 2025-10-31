#include <stdio.h>

struct Item {
    int value;
    int weight;
    double ratio;
};

void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

double fractionalKnapsack(int W, int val[], int wt[], int n) {
    struct Item items[n];

    // Step 1: calculate per item cost (value/weight)
    for (int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
        items[i].ratio = (double)val[i] / wt[i];
    }

    // Step 2: sort by decreasing ratio
    sortItems(items, n);

    // Step 3: pick items greedily
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int val[] = {60, 120, 100};
    int wt[] = {10, 30, 20};
    int W = 50;
    int n = 3;

    double maxProfit = fractionalKnapsack(W, val, wt, n);
    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
