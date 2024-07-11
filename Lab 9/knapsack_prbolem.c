#include <stdio.h>

// A utility function that returns the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Function to solve the Knapsack problem using Dynamic Programming
void knapsack(int W, int n, int weights[], int profits[]) {
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(profits[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Printing the table
    printf("DP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%d\t", K[i][w]);
        }
        printf("\n");
    }

    // Storing the result
    int res = K[n][W];
    printf("\nMaximum profit: %d\n", res);

    // Backtracking to find the items included in the knapsack
    int w = W;
    printf("Selected items:\n");
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            // This item is included
            printf("Item %d (Weight: %d, Profit: %d)\n", i, weights[i - 1], profits[i - 1]);

            // Since this weight is included, its profit is deducted
            res -= profits[i - 1];
            w -= weights[i - 1];
        }
    }
}

// Driver program to test the knapsack function
int main() {
    int weights[] = {2, 3, 4, 5};
    int profits[] = {3, 4, 5, 6};
    int W = 5;
    int n = sizeof(profits) / sizeof(profits[0]);

    knapsack(W, n, weights, profits);

    return 0;
}
