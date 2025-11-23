#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i, left = 2*i + 1, right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++) temp[i] = arr[i];
    clock_t t1 = clock();
    bubbleSort(temp, n);
    clock_t t2 = clock();
    double bubbleTime = (double)(t2 - t1) / CLOCKS_PER_SEC;
    for (i = 0; i < n; i++) temp[i] = arr[i];
    t1 = clock();
    insertionSort(temp, n);
    t2 = clock();
    double insertionTime = (double)(t2 - t1) / CLOCKS_PER_SEC;

    for (i = 0; i < n; i++) temp[i] = arr[i];
    t1 = clock();
    quickSort(temp, 0, n-1);
    t2 = clock();
    double quickTime = (double)(t2 - t1) / CLOCKS_PER_SEC;

    for (i = 0; i < n; i++) temp[i] = arr[i];
    t1 = clock();
    mergeSort(temp, 0, n-1);
    t2 = clock();
    double mergeTime = (double)(t2 - t1) / CLOCKS_PER_SEC;

    for (i = 0; i < n; i++) temp[i] = arr[i];
    t1 = clock();
    heapSort(temp, n);
    t2 = clock();
    double heapTime = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("\nSorted List (using Heap Sort): ");
    printArray(temp, n);

    printf("\n--- Time Comparison ---\n");
    printf("Bubble Sort     : %.6f seconds\n", bubbleTime);
    printf("Insertion Sort  : %.6f seconds\n", insertionTime);
    printf("Quick Sort      : %.6f seconds\n", quickTime);
    printf("Merge Sort      : %.6f seconds\n", mergeTime);
    printf("Heap Sort       : %.6f seconds\n", heapTime);

    return 0;
}
