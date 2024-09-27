class Solution {
public:
    int memFunc(vector<int>& nums, int& target, int indx, int sum, vector<vector<int>>& dp, int offset, int n) {
        if (indx >= n) {
            if (sum == target) return 1;
            return 0;
        }
        if (dp[indx][sum + offset] != -1) {
            return dp[indx][sum + offset];
        }
          
        int add = memFunc(nums, target, indx + 1, sum + nums[indx], dp, offset, n);
        int sub = memFunc(nums, target, indx + 1, sum - nums[indx], dp, offset, n);

        return dp[indx][sum + offset] = sub + add ;    
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int indx = 0, sum = 0, count = 0;

        int sum_nums = 0;
        for (int num : nums)
            sum_nums += num;

        int offset = sum_nums;
        vector<vector<int>> dp(n, vector<int>(2 * sum_nums + 1, -1));

        return memFunc(nums, target, indx, sum, dp, offset, n);
    }
};
