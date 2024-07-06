class Solution {
public:

    int memFunc(vector<vector<int>>& obstacleGrid, int m, int n, int row, int col, vector<vector<int>> &dp){
        if(row < m && col < n && obstacleGrid[row][col] == 1) return 0 ;
        if(row == m-1 && col == n-1) return 1; 
        if(row >= m || col >= n) return 0; 

        if(dp[row][col] != -1) return dp[row][col] ;

        dp[row][col] = memFunc(obstacleGrid, m, n, row+1, col, dp) + memFunc(obstacleGrid, m, n, row, col+1, dp); 

        return dp[row][col] ;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        int n = obstacleGrid[0].size() ;

        vector<vector<int>> dp(m, vector<int>(n, -1)); 

        return memFunc(obstacleGrid, m, n, 0, 0, dp) ;
    }
};