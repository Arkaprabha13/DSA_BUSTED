//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
long long int maxSumWithK(long long int a[], long long int n, long long int k) {
    // Initialize variables to keep track of the maximum subarray sum
    long long int maxEndingHere = 0;  // Maximum subarray sum ending at the current index
    long long int currentSum = 0;     // Current sum of the subarray
    long long int result = LLONG_MIN; // Overall maximum subarray sum

    for (long long int i = 0; i < n; ++i) {
        // Add the current element to the current subarray
        currentSum += a[i];

        // If the subarray size exceeds k, remove the first element of the subarray
        if (i >= k) {
            currentSum -= a[i - k];
            // maxEndingHere represents the maximum subarray sum ending at the current index
            // It can be either the current element, the sum of the previous subarray, or 0
            maxEndingHere = max(0LL, max(a[i - k], a[i - k] + maxEndingHere));
        }

        // If we have processed at least k elements, update the overall result
        if (i >= k - 1) {
            result = max(result, currentSum + maxEndingHere);
        }
    }

    return result;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
