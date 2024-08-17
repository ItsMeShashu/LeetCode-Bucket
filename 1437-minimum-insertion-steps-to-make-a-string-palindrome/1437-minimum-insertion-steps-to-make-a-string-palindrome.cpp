class Solution {
public:
    //FUNCTION OF LONGEST PALINDROMIC SUBSEQUENCE.....................
    int solveMem(string& s1, string& s2, int n, int m, int i, int j, vector<vector<int>>& dp) {
        if (i == n || j == m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + solveMem(s1, s2, n, m, i + 1, j + 1, dp);
        } 
        else {
            dp[i][j] = max(solveMem(s1, s2, n, m, i + 1, j, dp), solveMem(s1, s2, n, m, i, j + 1, dp));
        }

        return dp[i][j];
    }

    int minInsertions(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        int n = s.length();
        int m = revStr.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int longestPalindromeSubseq = solveMem(s, revStr, n, m, 0, 0, dp);

        return (s.length() - longestPalindromeSubseq) ;
    }
};