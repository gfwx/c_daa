#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key) {
        int left = 0;
        int right = n - 1;

        while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == key) {
                        return mid;
                }

                if (arr[mid] > key) {
                        right = mid - 1;
                }
                else {
                        left = mid + 1;
                }
        }

        return -1;
}

int main() {
        int n;
        printf("Enter size of array: \n");
        scanf("%d", &n);
        int arr[n];

        printf("Enter elements of array: \n");
        for (int i = 0; i < n; ++i) {
                scanf("%d", &arr[i]);
        }

        int k;
        printf("Enter key: \n");
        scanf("%d", &k);
        
        int res = binarySearch(arr, n, k);
        if (res == -1) {
                printf("Key not found!\n");
        }
        else {
                printf("Key found at idx=%d\n", res);
        }
}