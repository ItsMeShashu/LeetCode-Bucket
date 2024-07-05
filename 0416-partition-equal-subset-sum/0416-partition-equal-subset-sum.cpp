class Solution {
public:

    bool memFunc(vector<int>& nums, int index, int targetSum, int n, vector<vector<int>> &dp){
        if(targetSum == 0) return true; 
        if(targetSum < 0 || index >= n) return false; 

        if(dp[index][targetSum] != -1){
            return dp[index][targetSum] ;
        }

        bool include = memFunc(nums, index+1, targetSum - nums[index], n, dp);
        bool exclude = memFunc(nums, index+1, targetSum, n, dp);

        dp[index][targetSum] = (include || exclude);
        return  dp[index][targetSum] ;
    }

    bool canPartition(vector<int>& nums) {
        int  n = nums.size(); 
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) return false;
        int targetSum = totalSum / 2;

        vector<vector<int>>dp(n, vector<int>(targetSum+1, -1)); 

        return memFunc(nums, 0, targetSum, n, dp);
    }
};