#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int k) {
        for (int i = 0; i < n; ++i) {
                if (arr[i] == k) {
                        return i;
                }
        }
        return -1;
}

int main() {
        int n;
        printf("Enter size of array: \n");
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; ++i) {
                scanf("%d", &arr[i]);
        }

        int k;
        printf("Enter key to search for: \n");
        scanf("%d", &k);

        int res = linearSearch(arr, n, k);
        if (res == -1) {
                printf("Key not found\n");
        }
        else {
                printf("Key found at idx=%d\n", res);
        }
}