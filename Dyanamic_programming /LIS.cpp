//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int a[],int n,int current,int prev,vector<vector<int>>&dp)
    {
        if (current == n)
        {
            return 0;
        }
        if (dp[current][prev+1] != -1)
        {
            return dp[current][prev+1];
        }
        // include
        int include = 0;
        
        if (prev == -1 || a[current] > a[prev])
        {
            include = 1 + solve(a, n, current + 1, current, dp);
        }
        // exclude
        int exclude = 0 + solve(a, n, current + 1, prev, dp);
        dp[current][prev+1] = max(include, exclude); 
        return dp[current][prev+1];
    }
    
    
    
    int solve_tab(int a[],int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int current=n-1;current>=0;current--)
        {
            for(int prev=current-1;prev>=-1;prev--)//we can also use prev=n-1 but we are doing direct optimisation
            {
                // include
                int include = 0;
        
                if (prev == -1 || a[current] > a[prev])
                {
                    include = 1 + dp[current + 1][current+1];
                }
                // exclude
                int exclude = dp[current + 1][prev+1];
                dp[current][prev+1]=max(include,exclude);
                
            }
        }
        return dp[0][0];
    }
    int solve(int a[], int n)
{
    vector<int> dp(n + 1, 1); // Use a 1D array to store intermediate results
    int maxLen = 1;

    for (int current = n - 2; current >= 0; current--)
    {
        int currentMax = 1; // Initialize the maximum length for the current element

        for (int prev = current + 1; prev < n; prev++)
        {
            if (a[current] < a[prev])
            {
                currentMax = max(currentMax, 1 + dp[prev]);
            }
        }

        dp[current] = currentMax; // Store the maximum length for the current element
        maxLen = max(maxLen, currentMax); // Update the overall maximum length
    }

    return maxLen;
}

    
    
    
    // int longestSubsequence(int n, int a[])
    // {
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     // return solve(a,n,0,-1,dp);
    //     // return solve_tab(a,n);
    //     return solve(a,n);
    //   // your code here
    // }
/*
all the above code is of O(n^2)
but the below code is of O(nlogn)
*/
     int longestSubsequence(int n, int a[]){
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
           int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
           if(ans.size()==index)
           {
               ans.push_back(a[i]);
           }
           else
           {
               ans[index]=a[i];
           }
       }
       return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
