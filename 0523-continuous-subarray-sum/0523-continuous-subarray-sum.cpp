class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = -1;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = 0 ;

            if(k == 0)  rem = sum;
            else rem = sum % k ;

            if (mp.count(rem)) {
                if (i - mp[rem] > 1) {
                    return true;
                }
            } 
            else {
                mp[rem] = i;
            }
        }
        
        return false;
    }
};