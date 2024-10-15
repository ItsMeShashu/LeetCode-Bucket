class Solution {

    void solve(vector<int> nums, vector<vector<int>> &result, vector<int>subset, int i){
        if(i >= nums.size()){
            result.push_back(subset);
            return;
        }

        solve(nums, result, subset, i+1);

        int val = nums[i];
        subset.push_back(val);
        solve(nums, result, subset, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result ;
        vector<int>subset;
        int i = 0;
        solve(nums, result, subset, i);

        return result;
    }
};