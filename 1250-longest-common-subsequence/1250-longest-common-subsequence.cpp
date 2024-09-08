class Solution {
public:

    int solveMem(string &s1, string &s2, int n, int m, int i, int j, vector< vector<int> > &dp) {
        if(i==n || j==m ){
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        int same = 0 ; 
        int notSame = 0 ; 
        if(s1[i] == s2[j]){
            same = 1 + solveMem(s1, s2, n, m, i+1, j+1, dp); 
        }
        else{
            notSame = max(solveMem(s1, s2, n, m, i+1, j, dp), solveMem(s1, s2, n, m, i, j+1, dp)); 
        }

        return dp[i][j] = max(same, notSame) ; 
    }
    int solveTab(string &s1, string &s2, int n, int m) {
        vector< vector<int> >  dp(n+1, vector<int>(m+1, 0)) ;
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1]; 
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]); 
                }
            }
        }
        return dp[0][0] ; 
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(); 
        int m = text2.length();

        vector< vector<int> >  dp(n, vector<int>(m, -1)) ;
        return solveMem(text1, text2, n, m, 0 , 0, dp); 
        // return solveTab(text1, text2, n, m); 
    }
};