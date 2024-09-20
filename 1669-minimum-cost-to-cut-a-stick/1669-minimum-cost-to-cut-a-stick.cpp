class Solution {
public:
    int solve(int start_stick, int end_stick, vector<int>& cuts, int left, int right, vector<vector<int>> &dp){
        if(left > right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int cost = 1e9;
        
        for(int i=left; i<=right; i++){
            int left_cost = solve(start_stick, cuts[i], cuts, left, i-1, dp);
            int right_cost = solve(cuts[i], end_stick, cuts, i+1, right, dp);
            int curr_cost = (end_stick - start_stick) + left_cost + right_cost;
            cost = min(cost,curr_cost);
        }
        
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        int sz = cuts.size() ; 
        vector<vector<int>> dp(101, vector<int>(101, -1)); 
        sort(cuts.begin(),cuts.end());
        return solve(0, n, cuts, 0, sz-1, dp);
    }
};