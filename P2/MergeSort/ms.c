#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void display(int arr[], int n) {
        for (int i = 0; i < n; ++i) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

void merge(int *arr, int left, int mid, int right) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        int leftArr[leftSize];
        int rightArr[rightSize];

        for (int i = 0; i < leftSize; ++i) {
                leftArr[i] = arr[left + i];
        }

        for (int j = 0; j < rightSize; ++j) {
                rightArr[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;

        while (i < leftSize && j < rightSize) {
                if (leftArr[i] <= rightArr[j]) {
                        arr[k] = leftArr[i];
                        ++i;
                }
                else {
                        arr[k] = rightArr[j];
                        ++j;
                }
                ++k;
        }

        while (i < leftSize) {
                arr[k] = leftArr[i];
                ++k;
                ++i;
        }

        while (j < rightSize) {
                arr[k] = rightArr[j];
                ++k;
                ++j;
        }
}


void mergeSort(int * arr, int left, int right) {
        if (left < right) {
                int mid = left + (right - left) / 2;

                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                merge(arr, left, mid, right);
        }
}

int main() {
        int n;
        printf("Enter the number of elements:\n");
        scanf("%d", &n);

        int arr[n];
        srand(time(0));
        for (int i = 0; i < n; ++i) {
                arr[i] = rand() % 100 + 1;
        }

        display(arr, n);
        mergeSort(arr, 0, n-1);
        display(arr, n);
}
