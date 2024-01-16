#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the index of the pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at index i+1 (right position)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform QuickSort on the array
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot element
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform QuickSort
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
