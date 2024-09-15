class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp ;
        int sum = 0;
        int cnt = 0 ;
        mp[0] = 1 ; 
        for(int i=0; i<nums.size(); i++){
            sum += nums[i] ;
            // if(sum == goal) cnt++; 

            if(mp.find(sum-goal) != mp.end()){
                cnt += mp[sum-goal] ;
            }

            mp[sum]++ ;
        }
        return cnt ;
    }
};