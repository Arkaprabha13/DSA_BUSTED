class Solution {
public:
    int dp[101][101];
    
    // Recursive function to find the optimal compression length
    int dfs(string& s, int left, int K) {
        int k = K;
        // If remaining characters are less than or equal to k, return 0
        if (s.size() - left <= k) {
            return 0;
        }
        // If the result is already computed, return it
        if (dp[left][k] >= 0) {
            return dp[left][k];
        }

        int res;
        // If k is not zero, recursively call the function with reduced k
        if (k) {
            res = dfs(s, left + 1, k - 1);
        } else {
            // If k is zero, initialize res to a large value
            res = 10000;
        }

        int number_of_digits = 1;

        for (int i = left + 1; i <= s.size(); ++i) {
            int temp;
            // Determine the number of digits for the current character count
            if (number_of_digits >= 100) {
                temp = 3;
            } else if (number_of_digits >= 10) {
                temp = 2;
            } else if (number_of_digits > 1) {
                temp = 1;
            } else {
                temp = 0;
            }
            // Update the result with the minimum of current result and the recursive call
            res = min(res, dfs(s, i, k) + 1 + temp);

            if (i == s.size()) break;
            if (s[i] == s[left]) {
                ++number_of_digits;
            } else if (--k < 0) {
                break;
            }
        }
        // Save the result in dp array and return it
        return dp[left][K] = res;
    }

    // Wrapper function to initialize dp array and call the recursive function
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, k);
    }
};
