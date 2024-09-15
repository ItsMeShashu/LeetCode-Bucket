class Solution {
public:

    int memFunc(vector<int>& nums, vector<vector<int>> &dp, int s, int e){
        if(s > e){
            return 0; 
        }

        if(dp[s][e] != -1) return dp[s][e] ; 

        dp[s][e] = max(nums[s] - memFunc(nums, dp, s+1, e), nums[e] - memFunc(nums, dp, s, e-1)) ; 

        return dp[s][e] ; 
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();  
        vector<vector<int>> dp(n, vector<int>(n, -1)) ; 

        if(n%2 == 1) return memFunc(nums, dp, 0, n-1) >= 0 ;  //if scores equal then also p1 winner so true... 
        else return true ; 
        // Always true for even size array......  
    }
};