// C Program for 0-1 KnapSack Problem using Recursion
#include <stdio.h>

// Function to find maximum between two numbers
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// Returns the maximum value that can be put in a knapsack
// of capacity W
int knapsackRecursive(int W, int wt[], int val[], int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapsackRecursive(W, wt, val, n - 1);

    else
        return max(val[n - 1]
                       + knapsackRecursive(W - wt[n - 1],
                                           wt, val, n - 1),
                   knapsackRecursive(W, wt, val, n - 1));
}
// Driver Code
int main()
{
    int values[] = { 3, 4, 5, 6 };
    int weight[] = { 2, 3, 4, 5 };
    int W = 8;
    // Find the number of items
    int n = sizeof(values) / sizeof(values[0]);

    // Output the maximum profit for the knapSack
    printf(
        "Maximum value that can be put in knapsack: %d\n",
        knapsackRecursive(W, weight, values, n));

    return 0;
}
