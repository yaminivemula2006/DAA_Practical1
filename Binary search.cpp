#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform iterative binary search
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        // Prevents integer overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2; 

        if (arr[mid] == target) {
            return mid; // Target found, return index
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Target is in the right half
        }
        else {
            high = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers (in sorted ascending order):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Defensive check: guarantee the array is sorted before binary search
    if (!is_sorted(arr.begin(), arr.end())) {
        cout << "\n[Notice] Array was not sorted. Sorting it automatically...\n";
        sort(arr.begin(), arr.end());
    }

    cout << "Enter the value you want to search for: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << " (0-indexed position)\n";
    } else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
