#include <iostream>
#include <vector>

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array around a pivot element
int partition(std::vector<int>& arr, int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element, indicating the right position of pivot found so far
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    
    // Place the pivot in its correct sorted position
    swap(arr[i + 1], arr[high]);
    
    // Return the partitioning index
    return (i + 1);
}

// The main function that implements Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the elements of the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {10, 7, 8, 9, 1, 5};
    int n = data.size();
    
    std::cout << "Unsorted Array: ";
    printArray(data);
    
    // Call quickSort on the entire vector
    quickSort(data, 0, n - 1);
    
    std::cout << "Sorted Array:   ";
    printArray(data);
    
    return 0;
}
