class Solution {
public:

    int func(string &s, int i, int j, vector<vector<int> >&dp){
        if(i > j)
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];

        int x = i;
        while(x + 1 <= j && s[x] == s[x + 1])  x++ ; 

        int ans = 1 + func(s,x + 1, j, dp); 

        for(int k = x + 1; k <= j; k++){
            if(s[k] == s[i]){
                ans = min(ans, func(s,k,j, dp) + func(s,x + 1, k - 1, dp));  //solve(s, k, j) to find the minimum number of turns needed to print the rest of the substring after this character, and solve(s, x + 1, k - 1) to find the minimum number of turns needed to print the part of the substring between the first same character sequence and the current character
            }
        }
        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        int n = s.length() ; 
        vector<vector<int>> dp(n, vector<int>(n, -1)) ; 

        return func(s, 0, n-1, dp) ; 
    }
};