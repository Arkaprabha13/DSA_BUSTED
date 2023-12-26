//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    void getCofactor(const vector<vector<int>>& matrix, vector<vector<int>>& submatrix, int row, int col, int n) {
        int i = 0, j = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r != row && c != col) {
                    submatrix[i][j++] = matrix[r][c];
                    if (j == n - 1) {
                        j = 0;
                        ++i;
                    }
                }
            }
        }
    }
    //Function for finding determinant of matrix.
   int determinantOfMatrix(vector<vector<int>> matrix, int n) {
        // Base case: if the matrix is 1x1, return the only element
        if (n == 1) {
            return matrix[0][0];
        }

        int det = 0;  // Initialize determinant

        // Iterate through the first row to calculate the determinant
        for (int i = 0; i < n; ++i) {
            // Calculate the cofactor (excluding the current row and column)
            vector<vector<int>> submatrix(n - 1, vector<int>(n - 1, 0));
            getCofactor(matrix, submatrix, 0, i, n);
            
            // Add or subtract the product of the current element and its cofactor
        if (i % 2 == 0) 
            {
                det += matrix[0][i] * determinantOfMatrix(submatrix, n - 1);
            } 
        else
            {
                det -= matrix[0][i] * determinantOfMatrix(submatrix, n - 1);
            }
        }

        return det;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends
