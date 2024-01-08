class Solution {
public:
    int solve(vector<vector<int>>& t, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1) {
            return t[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(t, m, n, i + 1, j, dp) + t[i][j];
        int diagonal = solve(t, m, n, i + 1, j + 1, dp) + t[i][j];
        dp[i][j] = min(down, diagonal);
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size(); // The last row may have a different size

        // Initialize dp with -1 values
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start from the top of the triangle
        int ans = solve(triangle, m, n, 0, 0, dp);
        return ans;
    }
};
