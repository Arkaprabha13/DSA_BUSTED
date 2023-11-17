class Solution {
public:
int recursive_func(int m, int n, int i, int j,vector<vector<int>>&dp)
{
    // Base case: out of bounds
    if (i >= m || i < 0 || j >= n || j < 0) {
        return 0;
    }

    // If we reach the bottom-right cell, return 1
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    // Recursive calls for moving down and right
    int down = recursive_func(m, n, i + 1, j,dp);
    int right = recursive_func(m, n, i, j + 1,dp);

    // Return the sum of paths from down and right
    dp[i][j]=down+right;
    return dp[i][j];
}
    int uniquePaths(int m, int n) {
        int counter=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        counter = recursive_func(m,n,0,0,dp);
        return counter;
    }
};
