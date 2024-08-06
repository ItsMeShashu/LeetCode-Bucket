class Solution {
public:
    //........................O(n) extra
    //space.....................................
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     int n = nums.size() ;
    //     unordered_map<int , int> mp;
    //     vector<int> ans ;
    //     for(int i = 0; i<n ; i++){
    //         mp[nums[i]]++ ;
    //     }
    //     for(int i=1; i<=n; i++){
    //         if(mp[i] == 0) ans.push_back(i) ;
    //     }
    //     return ans;
    // }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto num : nums) {
            int i = abs(num) - 1;
            nums[i] = -1 * abs(nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};