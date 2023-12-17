//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n) 
{
	if (n == 0) return 0;
    if (n == 1) return arr[0];

    int incl = arr[0];
    int excl = 0;

    for (int i = 1; i < n; i++) {
        // Current max excluding arr[i] is max of incl and excl
        int new_excl = max(incl, excl);

        // Current max including arr[i] is excl + arr[i]
        incl = excl + arr[i];

        // Update excl to the new_excl
        excl = new_excl;
    }

    // Return the maximum of incl and excl
    return max(incl, excl);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
