#include <stdio.h> 

#include <stdlib.h> 

 

// Function to display the current state of the array 

 

void display(int arr[], int n) { 

    printf("Current Array: "); 

    for (int i = 0; i < n; i++) { 

        printf("%d ", arr[i]); // Added space after each number 

    } 

    printf("\n"); 

} 

 

// Function to swap two elements in the array 

 

void swap(int* a, int* b) { 

    int temp = *a; // Corrected syntax error 

    *a = *b; 

    *b = temp; 

} 

 

// Quick Sort 

 

void quickSort(int arr[], int low, int high) { 

    if (low < high) { 

        int pivot = arr[high]; 

        int i = low - 1; 

 

        for (int j = low; j < high; j++) { 

            if (arr[j] <= pivot) { 

                i++; 

                swap(&arr[i], &arr[j]); // Corrected the function call 

            } 

        } 

        swap(&arr[i + 1], &arr[high]); 

 

        display(arr, high + 1); 

 

        quickSort(arr, low, i); 

        quickSort(arr, i + 2, high); // Corrected the function call 

    } 

} 

 

// Insertion Sort 

 

void insertionSort(int arr[], int n) { 

    for (int i = 1; i < n; i++) { 

        int key = arr[i]; 

        int j = i - 1; 

 

        while (j >= 0 && arr[j] > key) { 

            arr[j + 1] = arr[j]; 

            j--; 

        } 

 

        arr[j + 1] = key; 

 

        display(arr, n); 

    } 

} 

 

// Heap Sort 

 

void heapify(int arr[], int n, int i) { 

    int largest = i; 

    int left = 2 * i + 1; 

    int right = 2 * i + 2; 

 

    if (left < n && arr[left] > arr[largest]) 

        largest = left; 

 

    if (right < n && arr[right] > arr[largest]) 

        largest = right; 

 

    if (largest != i) { 

        swap(&arr[i], &arr[largest]); 

        display(arr, n); 

 

        heapify(arr, n, largest); 

    } 

} 

 

void heapSort(int arr[], int n) { 

    for (int i = n / 2 - 1; i >= 0; i--) 

        heapify(arr, n, i); 

 

    for (int i = n - 1; i > 0; i--) { 

        swap(&arr[0], &arr[i]); 

        display(arr, n); 

 

        heapify(arr, i, 0); // Corrected the function call 

    } 

} 

 

int main() { 

    int n; 

    printf("Enter the number of elements in the array: "); 

    scanf("%d", &n); 

 

    int arr[n]; 

    printf("Enter the elements of the array: "); 

    for (int i = 0; i < n; i++) { 

        scanf("%d", &arr[i]); 

    } 

 

    int choice; 

    printf("Choose the sorting algorithm:\n"); 

    printf("1. Quick Sort\n"); 

    printf("2. Insertion Sort\n"); // Corrected numbering 

    printf("3. Heap Sort\n"); 

    scanf("%d", &choice); 

 

    printf("Initial Array: "); 

    display(arr, n); 

 

    switch (choice) { 

        case 1: 

            quickSort(arr, 0, n - 1); 

            break; 

 

        case 2: 

            insertionSort(arr, n); 

            break; 

 

        case 3: 

            heapSort(arr, n); 

            break; 

 

        default: 

            printf("Invalid Choice\n"); 

    } 

 

    printf("Sorted Array: "); 

    display(arr, n); 

 

    return 0; 

} 
