class Solution {
public:

    int solve_rec(vector<int>&nums,int n)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return nums[0];
        }
        
    // You have two choices at each step: include the current element or exclude it.
    // If you include the current element, you should skip the previous element.
    int include = nums[n] + solve_rec(nums, n - 2);
    // If you exclude the current element, you should consider the sum up to the previous element.
    int exclude = solve_rec(nums, n - 1);
    return max(include,exclude);

    }


    int solve_using_memo(vector<int>&nums,int n,vector<int>&dp)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return nums[0];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
   
        int include = nums[n] + solve_using_memo(nums, n - 2,dp);
    
        int exclude = solve_using_memo(nums, n - 1,dp);
        dp[n]= max(include,exclude);
        return max(include,exclude);

    }
    
int spaceOptimisedSolution(vector<int>& nums, int n ) {

    int prev2 = 0;
    int prev1 = nums[0];
    // vector<int> dp(n+1, 0);
    // dp[0] = nums[0];
    int curr = 0;
        for(int i=1; i<=n; i++) {

            int temp = 0;
            if(i-2>=0)
                temp = prev2;
            
            int include = temp + nums[i];
            int exclude = prev1 + 0;

            curr =  max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
    }

    return prev1;
}

    int solve_using_tabulation(vector<int>&nums,int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        if(n==0)
        {
            return nums[0];
        }
        for(int i=1;i<=n;i++)
        {
            int temp=0;
            if(i-2>=0)
            {
                temp = dp[i - 2];
            }   
            int include=temp+nums[i];
            int exclude = dp[i-1]+0;
            dp[i]= max(include,exclude);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        // vector<int>dp(n+1,-1);
        return spaceOptimisedSolution(nums,n);
    }
};
