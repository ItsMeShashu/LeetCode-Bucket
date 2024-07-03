class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if (i < 0 || j < 0) {
            return INT_MAX;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int up = INT_MAX;
        int left = INT_MAX;
        if (i > 0) {
            up = grid[i][j] + func(i - 1, j, dp, grid);
        }
        if (j > 0) {
            left = grid[i][j] + func(i, j - 1, dp, grid);
        }
        
        return dp[i][j] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, dp, grid); 
    }
};