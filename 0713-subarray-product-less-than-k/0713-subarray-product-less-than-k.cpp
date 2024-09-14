class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(k == 0){
            return 0;
        }
        int ans = 0 ;
        int pro = 1;
        int i = 0;
        for(int j = 0; j<n; j++){
            pro = pro * nums[j];

            while(pro >= k && i < j){
                pro /= nums[i];
                i++ ;
            }

            if(pro<k){
                ans += (j-i+1);
            }
        }

        return ans ;
    }
};