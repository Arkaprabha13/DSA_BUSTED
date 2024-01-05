//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
int mod = 1e9 + 7;

    // Recursion
    int rec(int i, int n) {
        if (i >= n)
            return 0;
        int a = 1 + rec(i + 2, n) % mod;
        int b = rec(i + 1, n) % mod;
        return (a + b) % mod;
    }

    // Memoization
    int rec1(int i, int n, vector<int>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int a = 1 + rec1(i + 2, n, dp) % mod;
        int b = rec1(i + 1, n, dp) % mod;
        return dp[i] = (a + b) % mod;
    }

    // Tabulation
    int TotalWaysTabulation(int n) {
        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i--) {
            int a = 1 + dp[i + 2] % mod;
            int b = dp[i + 1] % mod;
            dp[i] = (a + b) % mod;
        }
        int val = dp[0] + 1;
        return (1ll * val * val) % mod;
    }

    // Space Optimization
    int TotalWaysSpaceOptimization(int n) {
        int prev2 = 0, prev1 = 0, curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr = (1 + prev2 + prev1) % mod;
            prev2 = prev1;
            prev1 = curr;
        }
        int val = curr + 1;
        return (1ll * val * val) % mod;
    }

    int TotalWays(int n) {
        // Uncomment the method you want to use

        // Recursion
        // int val = rec(0, n) + 1;

        // Memoization
        // vector<int> dp(n + 2, -1);
        // int val = rec1(0, n, dp) + 1;

        // Tabulation
        // int val = TotalWaysTabulation(n);

        // Space Optimization
        int val = TotalWaysSpaceOptimization(n);

        return val;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
