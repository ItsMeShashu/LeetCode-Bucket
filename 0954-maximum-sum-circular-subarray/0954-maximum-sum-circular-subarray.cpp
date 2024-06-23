class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0, currMaxSum = 0, currMinSum = 0; 
        int maxSubarraySum = INT_MIN, minSubarraySum = INT_MAX;
        
        for (auto num : nums) {
            total_sum += num;
            currMaxSum += num;
            currMinSum += num;

            maxSubarraySum = max(maxSubarraySum, currMaxSum);
            if (currMaxSum < 0) currMaxSum = 0;

            minSubarraySum = min(currMinSum, minSubarraySum);
            if (currMinSum > 0) currMinSum = 0;
        }

        if(total_sum == minSubarraySum) return maxSubarraySum ; //when total sum is 0 or neg.

        else return max(maxSubarraySum, total_sum - minSubarraySum);
    }
};