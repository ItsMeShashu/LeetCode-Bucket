class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int>& nums, vector<int> vec, int index, int n) {
        if (index >= n) {
            st.insert(vec);
            return;
        }
        
        // Exclude the current element
        solve(nums, vec, index + 1, n);

        // Include the current element
        vec.push_back(nums[index]);
        solve(nums, vec, index + 1, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> vec;
        solve(nums, vec, 0, n);

        for (auto subset : st) {
            ans.push_back(subset);
        }

        return ans;
    }
};