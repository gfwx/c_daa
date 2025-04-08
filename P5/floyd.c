#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef MAX_WEIGHT
#define MAX_WEIGHT 1000
#endif

void display(int **arr, int n) {
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        printf("%d ", arr[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}

int min(int a, int b) {
        return a < b ? a : b;
}

int ** find_shortest_path(int **arr, int n) {
        int ** res = (int **) calloc(n, sizeof(int *));

        for (int i = 0; i < n; ++i) {
                res[i] = (int *) calloc(n, sizeof(int));
        }

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        res[i][j] = arr[i][j];
                }
        }


        for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                                res[i][j] = min(res[i][j], (res[i][k] + res[k][j]));
                        }
                }
        }

        return res;
}

int main() {
        int n;
        scanf("%d", &n);
        int ** arr = (int **) calloc(n, sizeof(int *));

        for (int i = 0; i < n; ++i) {
                arr[i] = (int *) calloc(n, sizeof(int));
        }

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        arr[i][j] = MAX_WEIGHT;
                        if (i == j) {
                                arr[i][j] = 0;
                        }
                }
        }

        for (int i = 0; i < n; ++i) {
                int v;
                printf("No. of adjacents for vert %d:\n", i);
                scanf("%d", &v);

                while (v--) {
                        int tmp;
                        int cost;

                        scanf("%d", &tmp);
                        scanf("%d", &cost);

                        if (tmp < 0 || tmp >= n || cost < 0) {
                                printf("Out of bounds\n");
                                ++v;
                        }
                        else if (tmp == i) {
                                printf("Self loops not allowed\n");
                                ++v;
                        }

                        else {
                                arr[i][tmp] = cost;
                        }
                }
        }

        int ** res = find_shortest_path(arr, n);

        printf("\nCurrent: \n");
        display(arr, n);

        printf("Shortest Path: \n");
        display(res, n);
}