class Solution {
public:
    int translate(int num, vector<int>& mapping){
        if(num == 0) return mapping[0];
        int res = 0 ;
        int val = 1; 
        while(num != 0){
            int digit = num%10; 
            res = mapping[digit] * val + res ;
            num = num/10 ;
            val = val*10;  
        } 
        return res ; 
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mp; 
        for(int num: nums){
            if(mp.find(num) == mp.end()){
                mp[num] = translate(num, mapping); 
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            return mp[a] < mp[b]; 
        }); 
        return nums; 
    }
};