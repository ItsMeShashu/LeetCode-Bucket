class Solution {
public:

    int memFunc(vector<int>& piles, vector<vector<int>> &dp, int s, int e){
        if(s >= e){
            return 0; 
        }

        if(dp[s][e] != -1) return dp[s][e] ; 

        dp[s][e] = max(piles[s] - memFunc(piles, dp, s+1, e), piles[e] - memFunc(piles, dp, s, e-1)) ; 

        return dp[s][e] ; 
    }


    bool stoneGame(vector<int>& piles) {
        int n = piles.size();  
        vector<vector<int>> dp(n, vector<int>(n, -1)) ; 

        return memFunc(piles, dp, 0, n-1) != 0 ; 
    }
};