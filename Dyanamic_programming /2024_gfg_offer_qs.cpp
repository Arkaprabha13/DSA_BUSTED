//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
int helper(int i, vector<int> &cost, int total, int n, vector<vector<int>> &dp) {
    // Base case: if total is less than or equal to 0 or all courses are considered
    if (total <= 0 || i == n) {
        return 0;
    }

    // Check if the result for the current parameters (i, total) is already memoized
    if (dp[i][total] != -1) {
        return dp[i][total];
    }

    int a = 0, b = 0;

    // Case when we can buy the course and we actually buy the course
    if (cost[i] <= total) {
        // Calculate the remaining total after buying the course (considering 10% refund)
        int remainingTotalAfterBuying = floor(total - cost[i] * 0.1);
        // Recursively call helper for the next course with updated parameters
        a = 1 + helper(i + 1, cost, remainingTotalAfterBuying, n, dp);
    }

    // Case when we don't buy the course
    b = helper(i + 1, cost, total, n, dp);

    // Store the maximum of a and b in the dp table for the current parameters
    dp[i][total] = max(a, b);

    // Return the maximum value for the current parameters
    return dp[i][total];
}

int max_courses(int n, int total, vector<int> &cost) {
    // DP vector to memoize intermediate results
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
    // Call the helper function to get the maximum number of courses
    return helper(0, cost, total, n, dp);
}
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends
