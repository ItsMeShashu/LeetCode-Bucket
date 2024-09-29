class Solution {
public:

    void solve(vector<int> nums, int i, set<vector<int>> &st) {
        if (i >= nums.size()) {
            st.insert(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); j++) {
            swap(nums[j], nums[i]);

            solve(nums, i + 1, st);

            swap(nums[j], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> st ;

        int i = 0;
        solve(nums, i, st);

        for(auto vec: st){
            result.push_back(vec) ; 
        }
        
        return result;
    }
};

    // void solve(vector<int> nums, int i, set<vector<int>> &st) {
    //     if (i >= nums.size()) {
    //         st.insert(nums);
    //         return;
    //     }
        
    //     for (int j = i; j < nums.size(); j++) {
    //         swap(nums[j], nums[i]);

    //         solve(nums, i + 1, st);

    //         swap(nums[j], nums[i]);
    //     }
    // }

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> result;
    //     set<vector<int>> st ;

    //     int i = 0;
    //     solve(result, nums, i, st);

    //     for(auto vec: st){
    //         result.push_back(vec) ; 
    //     }

    //     return result;
    // }