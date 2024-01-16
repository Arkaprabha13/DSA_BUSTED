#include <iostream>
#include <vector>

using namespace std;

void cocktailShakerSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped = true;

    int start = 0;
    int end = n - 1;

    while (swapped) {
        // Perform a pass from left to right
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // If no swaps occurred, the array is already sorted
        if (!swapped) {
            break;
        }

        // Update the end index after the right-to-left pass
        --end;

        // Perform a pass from right to left
        swapped = false;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Update the start index after the left-to-right pass
        ++start;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cocktailShakerSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
