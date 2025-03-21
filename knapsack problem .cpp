#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem
int knapsack(int maxWeight, int weights[], int values[], int n) {
    int dp[n + 1][maxWeight + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no item or no capacity
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];  // Exclude the item
            }
        }
    }

    // The result is stored in the last cell
    return dp[n][maxWeight];
}

int main() {
    int n, maxWeight;

    // Take input for the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input validation for the number of items
    if (n <= 0) {
        printf("The number of items must be greater than 0.\n");
        return 1;
    }

    int values[n], weights[n];

    // Take input for values and weights of items
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
        if (values[i] < 0) {
            printf("Values must be non-negative.\n");
            return 1;
        }
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
        if (weights[i] <= 0) {
            printf("Weights must be positive.\n");
            return 1;
        }
    }

    // Take input for the maximum weight capacity
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &maxWeight);

    // Input validation for maxWeight
    if (maxWeight <= 0) {
        printf("Maximum weight capacity must be greater than 0.\n");
        return 1;
    }

    // Solve the knapsack problem
    int result = knapsack(maxWeight, weights, values, n);
    printf("Maximum value in knapsack: %d\n", result);

    return 0;
}

