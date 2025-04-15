#include <stdio.h>
#include <stdlib.h>

void display(int **arr, int n) {
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        printf("%d ", arr[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}

void find_transitive_closure(int **arr, int n) {
        for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j) {
                                arr[i][j] = arr[i][j] | (arr[i][k] & arr[k][j]);
                        }
                }
        }
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
                        arr[i][j] = 0;
                }
        }

        for (int i = 0; i < n; ++i) {
                int v;
                printf("No. of adjacents for vert %d:\n", i);
                scanf("%d", &v);

                while (v--) {
                        int tmp;
                        scanf("%d", &tmp);
                        if (tmp < 0 || tmp >= n) {
                                printf("Out of bounds");
                                ++v;
                        } else {
                                arr[i][tmp] = 1;
                        }
                }
        }
        printf("Before: \n");
        display(arr, n);
        printf("After: \n");
        find_transitive_closure(arr, n);
        display(arr, n);
}