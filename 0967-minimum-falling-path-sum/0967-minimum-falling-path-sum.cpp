class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); 
        vector<vector<int>> dp(n,vector<int>(m,0)); 
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j] ;
        }

        for(int i=1; i<n; i++){    
            for(int j=0; j<m; j++){            
                int ld = INT_MAX;
                int rd = INT_MAX; 
                int upper = matrix[i][j] + dp[i-1][j] ;  //just above

                if(j-1 >= 0){
                    ld = matrix[i][j] + dp[i-1][j-1] ;  //diagonally left
                }
                if(j+1 < m){
                    rd = matrix[i][j] + dp[i-1][j+1] ;  //diagonally right
                } 

                dp[i][j] = min(upper, min(ld, rd)) ;
            }
        }
        int minVal = dp[n-1][0]; 
        //will take minimum from the last row.......
        for(int j=1; j<m; j++){
            minVal = min(minVal, dp[n-1][j]) ;
        }
        return minVal ; 
    }
};