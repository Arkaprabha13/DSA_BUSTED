//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int arr[], int N, int K, long long mid) {
    int count = 1;
    long long currentSum = 0;

    for (int i = 0; i < N; ++i) {
        currentSum += arr[i];
        if (currentSum > mid) {
            currentSum = arr[i];
            count++;
        }
    }

    return count <= K;
}


int splitArray(int arr[], int N, int K) {
    long long low = *std::max_element(arr, arr + N);  // Initialize the lower bound of the search space
    long long high = 0;  // Initialize the upper bound of the search space

    for (int i = 0; i < N; ++i) {
        high += arr[i];  // Calculate the sum of all elements in the array to set the upper bound
    }

    long long result = LLONG_MAX;  // Initialize the result variable to store the minimum possible maximum subarray sum

    while (low <= high) {
        long long mid = low + (high - low) / 2;  // Calculate the mid value for binary search

        if (isPossible(arr, N, K, mid)) {
            result = std::min(result, mid);  // Update the result if the current mid is valid
            high = mid - 1;  // Adjust the upper bound of the search space
        } else {
            low = mid + 1;  // Adjust the lower bound of the search space
        }
    }

    return static_cast<int>(result);  // Return the minimum possible maximum subarray sum
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
