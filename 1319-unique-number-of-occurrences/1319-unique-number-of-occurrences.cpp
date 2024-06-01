class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        set<int>s ;

        for(int i =0; i<arr.size(); i++){
            mp[arr[i]]++; 
        }

        for(auto i: mp){
            s.insert(i.second); 
        }
        
        if(s.size() == mp.size()) return true ;
        return false ; 
    }
};