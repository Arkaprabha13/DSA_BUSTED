class Solution {
public:
 int exploreSquare(const std::vector<std::vector<char>>& matrix, int i, int j, int m, int n,vector<vector<int>>&dp) {
        // Base case: If we reach the boundary or encounter '0', return 0
        if (i == m || j == n || matrix[i][j] == '0') {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        // Recursive case: Explore the square to the right, down, and diagonally down-right
        int right = exploreSquare(matrix, i, j + 1, m, n,dp);
        int down = exploreSquare(matrix, i + 1, j, m, n,dp);
        int diagonal = exploreSquare(matrix, i + 1, j + 1, m, n,dp);

        // The size of the square at the current position is 1 + the minimum of the explored squares
        int size = 1 + min({right, down, diagonal});
        dp[i][j]=size;
        return size;
}
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int maxSquare = 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // Iterate through each cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    // Start a recursive search for a square starting from this cell
                    maxSquare = max(maxSquare, exploreSquare(matrix, i, j, m, n,dp));
                }
            }
        }

        return maxSquare * maxSquare;
    }
};
