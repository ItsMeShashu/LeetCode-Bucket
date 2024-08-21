class Solution {
public:

    int func(string s, int indx, vector<int> &dp){
        if(s[indx] == '0') return 0 ; 
        if(indx == s.length()) return 1 ; 

        if(dp[indx] != -1) return dp[indx] ; 

        int ways = func(s, indx+1, dp) ;

        if(indx + 1 < s.length() && (s[indx] == '1' || (s[indx] == '2' && s[indx + 1] <= '6'))){
            ways += func(s, indx + 2, dp) ; 
        }

        dp[indx] = ways ; 
        return dp[indx] ; 
    }

    int numDecodings(string s) {
        int n = s.length() ; 
        vector<int> dp(n, -1) ; 
        return func(s, 0, dp) ; 
    }
};