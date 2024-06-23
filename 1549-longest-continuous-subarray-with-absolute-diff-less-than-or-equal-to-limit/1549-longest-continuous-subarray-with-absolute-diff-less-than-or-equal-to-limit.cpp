class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increase;
        deque<int> decrease;
        int maxLen = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            while (!increase.empty() && nums[j] < increase.back()) {
                increase.pop_back();
            }
            increase.push_back(nums[j]);

            while (!decrease.empty() && nums[j] > decrease.back()) {
                decrease.pop_back();
            }
            decrease.push_back(nums[j]);

            while (decrease.front() - increase.front() > limit) {
                if (nums[i] == decrease.front()) {
                    decrease.pop_front();
                }
                if (nums[i] == increase.front()) {
                    increase.pop_front();
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};