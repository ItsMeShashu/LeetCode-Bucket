class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid, int rows, int cols) {
        if (i == rows-1 && j == cols-1) {
            return grid[i][j];
        }
        if (i >= rows || j >= cols) {
            return INT_MAX;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int down = INT_MAX;
        int right = INT_MAX;
        if (i < rows-1) {
            down = grid[i][j] + func(i + 1, j, dp, grid, rows, cols);
        }
        if (j < cols-1) {
            right = grid[i][j] + func(i, j + 1, dp, grid, rows, cols);
        }       
        return dp[i][j] = min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(0, 0, dp, grid, m, n); 
    }
};