class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result ;
        unordered_map<int, int> mp;
        for(int num : nums1){
            mp[num]++; 
        }

        for(int num: nums2){
            if(mp.find(num) != mp.end()){
                result.push_back(num); 
                mp[num]--;
                if(mp[num] == 0) mp.erase(num);  
            }
        }

        return result; 
    }
};