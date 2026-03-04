#include <stdio.h>
#include <stdlib.h>

int* KnapsackGreedy(int *w, int *v, int n, int Wx) {
    int *x = (int*)malloc(n * sizeof(int));
    int i, j;

    for(i = 0; i < n; i++)
        x[i] = 0;

    int index[n];
    for(i = 0; i < n; i++)
        index[i] = i;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            double r1 = (double)v[index[i]] / w[index[i]];
            double r2 = (double)v[index[j]] / w[index[j]];
            if(r2 > r1) {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        int k = index[i];
        if(w[k] <= Wx) {
            x[k] = 1;
            Wx -= w[k];
        }
    }

    return x;
}

int main() {
    int n = 5, Wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackGreedy(w, v, n, Wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    free(x);
    return 0;
}
