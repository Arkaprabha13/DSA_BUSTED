class Solution {
public:
int recursiveDecode(const string& s, int index , vector<int>&dp) {
        // Base case: reached the end of the string, one valid decoding
        if (index == s.length()) {
            return 1;
        }

        // Check if the current digit is '0', it cannot be a valid mapping
        if (s[index] == '0') {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }

        // Count ways for single digit decoding
        int ways = recursiveDecode(s, index + 1,dp);

        // Count ways for two digit decoding if possible
        if (index + 1 < s.length() && stoi(s.substr(index, 2)) <= 26) {
            ways += recursiveDecode(s, index + 2,dp);
        }
        dp[index]=ways;
        return dp[index];
    }
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,-1);
        return recursiveDecode(s,0,dp);
    }
};
