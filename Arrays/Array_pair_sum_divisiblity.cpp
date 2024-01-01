//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2 != 0)
        {
            return false;
        }
        unordered_map<int,int> remainder_count;
        
        for(int num : nums)
        {
            int remainder=(num % k + k) % k;
            remainder_count[remainder]++;
        }
        
        if (remainder_count[0] % 2 != 0)
        {
            return false;
        }
        for (int i = 1; i <= k / 2; ++i) {
            if (remainder_count[i] != remainder_count[k - i]) 
            {
                return false;
            }
        }

    return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
