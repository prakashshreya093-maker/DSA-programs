#include <stdio.h>
#include <time.h>
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    clock_t start = clock();
    int linIndex = linearSearch(arr, n, key);
    clock_t end = clock();
    double linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    sortArray(arr, n);

    start = clock();
    int binIndex = binarySearch(arr, n, key);
    end = clock();
    double binaryTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n--- RESULTS ---\n");

    if (linIndex != -1)
        printf("Linear Search: Element found at index %d.\n", linIndex);
    else
        printf("Linear Search: Element NOT found.\n");

    if (binIndex != -1)
        printf("Binary Search: Element found at sorted index %d.\n", binIndex);
    else
        printf("Binary Search: Element NOT found.\n");

    printf("\n--- Time Comparison ---\n");
    printf("Linear Search Time : %.10f seconds\n", linearTime);
    printf("Binary Search Time : %.10f seconds\n", binaryTime);

    return 0;
}
