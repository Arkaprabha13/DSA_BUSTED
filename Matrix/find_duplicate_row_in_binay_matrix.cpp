//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int R, int N) 
    { 
        // Your code here
    unordered_set<string> seenRows; // Set to store string representation of rows
    vector<int> result; // Vector to store indices of duplicate rows

    for (int i = 0; i < R; ++i) {
        string rowString(matrix[i].begin(), matrix[i].end()); // Convert row to string

        // Check if the rowString is already present in the set
        if (seenRows.find(rowString) != seenRows.end()) {
            result.push_back(i); // Add index to result if it's a duplicate
        } else {
            seenRows.insert(rowString); // Add the rowString to the set if it's not a duplicate
        }
    }

    return result;
      
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends
