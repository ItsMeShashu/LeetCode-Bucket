class Solution {
public:
    int memFunc(int n, int m, string& s, string& t, vector<vector<int>>& dp, int i, int j) {
        if (j == m)
            return 1; 
        if (i == n)
            return 0; 

        if (dp[i][j] != -1)
            return dp[i][j];
        
        int include = 0 ;
        if (s[i] == t[j]) {
            include = memFunc(n, m, s, t, dp, i + 1, j + 1); 
        }
        int exclude = memFunc(n, m, s, t, dp, i + 1, j); // Skip 

        dp[i][j] = include + exclude;
        return dp[i][j] ;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memFunc(n, m, s, t, dp, 0, 0);
    }
};