class Solution {
public:
     int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Create a memoization table to store results of subproblems
        vector<vector<vector<int>>> memo(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        // Start the recursion from the top row, columns of robot 1, columns of robot 2
        return max(0, backtrack(grid, memo, 0, 0, cols - 1));
    }
    
    int backtrack(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int row, int col1, int col2) {
        int rows = grid.size();
        int cols = grid[0].size();
        // If this state has been computed before, return its result from the memo table
        if (memo[row][col1][col2] != -1)
            return memo[row][col1][col2];
        // Base case: if we're at the bottom row, return the cherry value at this cell
        if (row == rows - 1)
            return grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);
        // Calculate the current cherry value
        int cherries = grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);
        int maxCherries = 0;
        // Iterate through all possible moves for both robots
        for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; ++newCol1) {
            for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; ++newCol2) {
                // Ensure both robots are within the grid
                if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols) {
                    // Recursively calculate the maximum cherries obtained from the next row
                    maxCherries = max(maxCherries, backtrack(grid, memo, row + 1, newCol1, newCol2));
                }
            }
        }
        // Update the memo table with the maximum cherries obtained from this state
        return memo[row][col1][col2] = cherries + maxCherries;
    }
};
