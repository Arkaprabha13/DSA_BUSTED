class Solution {
public:
const int MOD = 1e9 + 7;

int solve(int m,int n,int i,int j,int k,vector<vector<vector<int>>>&dp)
{
    if(i<0 || i>=m || j<0 ||j>=n)
    {
        return 1;
    }
    if(k==0)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    int ways=0;
    ways = (ways + solve(m,n,i - 1, j, k - 1,dp)) % MOD;
    ways = (ways + solve(m,n,i + 1, j, k - 1,dp)) % MOD;
    ways = (ways + solve(m,n,i, j - 1, k - 1,dp)) % MOD;
    ways = (ways + solve(m,n,i, j + 1, k - 1,dp)) % MOD;

    return dp[i][j][k] = ways;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(m,n,startRow,startColumn,maxMove,dp);
    }
};
