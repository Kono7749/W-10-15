#include <stdio.h>
#include <stdlib.h>

int bestValue = 0;

void backtrack(int w[], int v[], int n, int W, int i, int cw, int cv, int x[], int bestx[])
{
    if(i == n)
    {
        if(cv > bestValue)
        {
            bestValue = cv;
            for(int j = 0; j < n; j++)
                bestx[j] = x[j];
        }
        return;
    }

    if(cw + w[i] <= W)
    {
        x[i] = 1;
        backtrack(w, v, n, W, i+1, cw + w[i], cv + v[i], x, bestx);
    }

    x[i] = 0;
    backtrack(w, v, n, W, i+1, cw, cv, x, bestx);
}

int KnapsackBT(int w[], int v[], int n, int W, int i, int x[])
{
    int *bestx = (int*)malloc(n * sizeof(int));
    int *temp = (int*)malloc(n * sizeof(int));

    for(int j = 0; j < n; j++)
    {
        bestx[j] = 0;
        temp[j] = 0;
    }

    backtrack(w, v, n, W, 0, 0, 0, temp, bestx);

    for(int j = 0; j < n; j++)
        x[j] = bestx[j];

    free(bestx);
    free(temp);

    return bestValue;
}

int main()
{
    int n = 5, W = 11;
    int w[5] = {1,2,5,6,7};
    int v[5] = {1,6,18,22,28};
    int *x, vx;

    x = (int*)malloc(n * sizeof(int));

    vx = KnapsackBT(w, v, n, W, 0, x);

    printf("Value = %d\n", vx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    free(x);
    return 0;
}