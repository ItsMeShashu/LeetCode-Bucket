class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size() ; 
        unordered_map<int , int> mp; 
        vector<int> ans ; 

        for(int i = 0; i<n ; i++){
            mp[nums[i]]++ ;
        }

        for(int i=1; i<=n; i++){
            if(mp[i] == 0) ans.push_back(i) ; 
        }
        return ans;
    }
};