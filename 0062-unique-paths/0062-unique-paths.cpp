class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return memFunc(m, n, 0, 0,dp);
    }

    int memFunc(int m, int n, int row, int col, vector<vector<int>>&dp) {
        if (row == m-1 && col == n-1) {
            return 1;
        }
        if (row >= m || col >= n) {
            return 0;
        }

        if(dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = memFunc(m, n, row + 1, col,dp) + memFunc(m, n, row, col + 1,dp);
    }
};