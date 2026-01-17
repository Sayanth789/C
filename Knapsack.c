#include <stdio.h>

int max(int a, int b) {return (a > b)? a : b;}
// Returns the maximum value that can be put in a knapsack of capacity W.
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int k[n+1][W+1];

    // Build table K[][] in bottom up manner 
    for (i = 0; i<= n; i++) {
        for (w=0; w<=W; w++) {
            if (i==0 || w==0) 
                k[i][w] = 0;
            else if (wt[i-1] <= w)
                k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]], k[i-1][w]);
            else 
                k[i][w] = k[i-1][w];

        }
    }

    return k[n][w];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int w = 50;
    
    int n = sizeof(val)/sizeof(val[0]);
    printf("\nValue = %d", knapsack(w, wt, val, n));
    return 0;
}