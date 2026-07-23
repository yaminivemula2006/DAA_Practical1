#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    // Loop through every element sequentially
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if the target is not in the array
}

int main() {
    int size, target;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
    cin >> target;

    // Call the linear search function
    int result = linearSearch(arr, size, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
