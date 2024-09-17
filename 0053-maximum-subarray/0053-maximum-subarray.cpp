class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxiSum = INT_MIN;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            maxiSum = max(sum, maxiSum); 
            if(sum < 0) {
                sum = 0;
            }
        }
        return maxiSum;
    }
};