class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1), count(n, 1);
        int maxLength = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[i] == dp[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        int numberOfLIS = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLength) {
                numberOfLIS += count[i];
            }
        }
        return numberOfLIS;
    }
};