// #include <vector>
// #include <climits> // for INT_MAX


/*
memozitation last case TLE
int minFallingPath(vector<vector<int>>& matrix, int i, int j) {
        if (i == matrix.size() - 1) {
            return matrix[i][j];
        }

        int left = (j > 0) ? minFallingPath(matrix, i + 1, j - 1) : INT_MAX;
        int down = minFallingPath(matrix, i + 1, j);
        int right = (j < matrix.size() - 1) ? minFallingPath(matrix, i + 1, j + 1) : INT_MAX;

        return matrix[i][j] + min(left,min(down, right));
    }

*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Create a DP table to store the minimum falling path sum for each position
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the DP table with the values from the last row of the matrix
        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // Start filling the DP table from the second-to-last row up to the first row
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the minimum falling path sum for the current position
                int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int down = dp[i + 1][j];
                int right = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;

                // Update the DP table with the minimum falling path sum
                dp[i][j] = matrix[i][j] + min(left, min(down, right));
            }
        }

        // Find the minimum falling path sum in the first row of the DP table
        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[0][j]);
        }

        return minSum;
    }
};
