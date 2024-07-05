class Solution {
public:
    void memFunc(vector<int>& nums, int& target, int indx, int sum, int& count, vector<vector<int>>& dp, int offset, int n) {
        if (indx >= n) {
            if (sum == target) count++;
            return;
        }

        if (dp[indx][sum + offset] != -1) {
            count += dp[indx][sum + offset];
            return;
        }

        int initial_count = count; // Store the initial count

        memFunc(nums, target, indx + 1, sum + nums[indx], count, dp, offset, n);
        memFunc(nums, target, indx + 1, sum - nums[indx], count, dp, offset, n);

        dp[indx][sum + offset] = count - initial_count; // Store the change in count
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int indx = 0, sum = 0, count = 0;

        int sum_nums = 0;
        for (int num : nums)
            sum_nums += num;

        int offset = sum_nums;
        vector<vector<int>> dp(n, vector<int>(2 * sum_nums + 1, -1));

        memFunc(nums, target, indx, sum, count, dp, offset, n);

        return count;
    }
};
