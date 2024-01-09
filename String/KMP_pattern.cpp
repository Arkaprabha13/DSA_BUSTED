//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
void computeLPS(string pat, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string pat, string txt) {
    vector<int> result;
    int m = pat.length();
    int n = txt.length();

    // Create an array to store the Longest Prefix Suffix values
    vector<int> lps(m, 0);
    computeLPS(pat, lps);

    int i = 0;  // index for txt
    int j = 0;  // index for pat

    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            // Pattern found at index i - j + 1
            result.push_back(i - j + 1);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (result.empty()) {
        result.push_back(-1);
    }

    return result;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
