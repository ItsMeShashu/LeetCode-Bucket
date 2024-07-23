class Solution {
public:

    static bool comp(pair<int,int>&a, pair<int,int>&b){
        if(a.second == b.second) return a.first > b.first ;
        else return (a.second < b.second); 
    }

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int, int> mp; 
        for(auto i: nums){
            mp[i]++; 
        }
        vector<pair<int, int>>vec(mp.begin(), mp.end()) ;
        vector<int>ans; 
        sort(vec.begin(), vec.end(), comp);

        for(auto it: vec){
            for(int i=0; i<it.second; i++){
                ans.push_back(it.first); 
            }
        }

        return ans; 
    }
};