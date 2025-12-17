#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function — chooses a pivot and arranges elements
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot = last element
    int i = (low - 1);     // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  // if current element is smaller than pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // place pivot at correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // partitionIndex is where the pivot ends up
        int partitionIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
