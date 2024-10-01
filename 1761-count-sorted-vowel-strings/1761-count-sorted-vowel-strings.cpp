class Solution {
public:
    int count(int i, int n, string &vowels, std::vector<std::vector<int>>& dp) {
        if (n == 0) return 1; // i = character, n = length  
        if (i >= 5) return 0;
        if (dp[i][n] != -1) return dp[i][n];
        int pick,not_pick;
         pick= count(i, n-1, vowels, dp);
        not_pick =  count(i+1, n, vowels, dp);
        dp[i][n] =  pick + not_pick;
        return dp[i][n];
    }

    int countVowelStrings(int n){
        string vowels = "aeiou";
        vector<vector<int>> dp(5,vector<int>(n + 1, -1));
        return count(0, n, vowels, dp);
    }
};