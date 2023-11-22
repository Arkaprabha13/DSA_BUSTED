//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
 bool wordBreakHelper(string s, unordered_set<string>& wordSet, unordered_map<string, int>& memo) {
        if (s.empty()) {
            return true;
        }

        // Check if the result is already memoized
        if (memo.count(s) > 0) {
            return memo[s];
        }

        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix) && wordBreakHelper(s.substr(i), wordSet, memo)) {
                // Memoize the result before returning
                memo[s] = 1;
                return 1;
            }
        }

        // Memoize the result before returning
        memo[s] = 0;
        return 0;
    }
    int wordBreak(string s, vector<string> &wordDict) {
        //code here
         unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, int> memo; // Memoization map
        return wordBreakHelper(s, wordSet, memo);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
