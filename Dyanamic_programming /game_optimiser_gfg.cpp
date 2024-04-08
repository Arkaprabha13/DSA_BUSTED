class Solution{
    public:
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long >>dp(n+1,vector<long long>(n+1,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=arr[i];
        }
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<=n-i;j++)
            {
                int k=j+i-1;
                // jodi ami j niyeni tale o j+1 ba k nite parbe
                long long picking_j= arr[j] + min(dp[j + 2][k], dp[j + 1][k - 1]);
                // jodi ami k niyeni tale o j ba k-1 nite parbe
                long long picking_k = arr[k] + min(dp[j + 1][k - 1], dp[j][k- 2]);
                dp[j][k]=max(picking_j,picking_k);
            }
        }
        return dp[0][n-1];
    }
};
