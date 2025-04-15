#include <stdio.h>

void swap(int * p1, int * p2) {
    int t1 = *p1;
    *p1 = *p2;
    *p2 = t1;
}

void display(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int left, int right) {
    int pivot = right;
    int store_idx = left;

    for (int i = left; i < right; ++i) {
        if (arr[i] < arr[pivot]) {
            swap(arr + i, arr + store_idx);
            ++store_idx;
        }
    }

    swap(arr + store_idx, arr + pivot);
    return store_idx;
}

void qsort(int *arr, int left, int right) {
    if (left < right) {
        int pivot_idx = partition(arr, left, right);
        qsort(arr, left, pivot_idx - 1);
        qsort(arr, pivot_idx + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, 0, n - 1);
    display(arr, n);
}