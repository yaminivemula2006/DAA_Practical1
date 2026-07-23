#include <iostream>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    
    // Outer loop for each pass
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Inner loop to compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element is greater than the next element
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true; // Set flag to true if a swap happens
            }
        }
        
        // Optimization: If no elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]);
    
    std::cout << "Original array: ";
    printArray(data, n);
    
    bubbleSort(data, n);
    
    std::cout << "Sorted array in ascending order: ";
    printArray(data, n);
    
    return 0;
}
