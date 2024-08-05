class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp ; 
        for(auto str:arr){
            mp[str]++; 
        }

        // int count = 0 ;
        for(auto str: arr){
            if(mp[str] == 1) k-- ;
            if(k == 0) return str ; 
        }

        return "" ; 
    }
};