#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A utility function to get the maximum value in an array
int getMax(vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

// Using counting sort to sort elements based on significant places
void countingSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    const int range = 10;  // 0 to 9

    vector<int> output(n, 0);
    vector<int> count(range, 0);

    // Count the occurrences of each digit at current place
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count[i] to store the position of the next occurrence
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Perform counting sort for every digit place
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
