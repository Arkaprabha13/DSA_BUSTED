#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Create buckets
    vector<vector<float>> buckets(n);

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate the buckets to get the sorted array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};

    cout << "Original array: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
