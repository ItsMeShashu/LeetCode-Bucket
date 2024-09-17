class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size() ; 
        sort(nums.begin(), nums.end()) ; 
        int s = 0; 
        int e = n-1 ; 
        int ans = INT_MIN; 

        while(s < e){
            ans = max(ans, nums[s]+nums[e]) ; 
            s++; 
            e-- ; 
        }

        return ans ; 
    }
};