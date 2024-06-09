class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int sum = 0 ; 
        int count = 0; 
        mp[sum] = 1 ;

        for(int num : nums){
            sum += num ;
            int mod = sum % k ;

            if(mod < 0) mod += k ;

            if(mp.count(mod) > 0){
                count += mp[mod] ;
            }
            mp[mod]++ ;
        }

        return count ;
    }
};