class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp ; 
        for(string str: words){
            mp[str]++ ;
        }

        vector<pair<int, string>> vec ; 

        for(auto m: mp){
            vec.push_back({m.second, m.first}) ; 
        }

        sort(vec.begin(), vec.end(), [](pair<int, string>&p1, pair<int, string> &p2){
            if(p1.first == p2.first) return p1.second < p2.second ; 
            else return p1.first > p2.first ; 
        });  

        vector<string> ans; 
        int i = 0 ; 
        for(int i=0; i<vec.size(); i++){
            if(k){
                ans.push_back(vec[i].second) ;
                k-- ; 
            }
        }

        return ans; 
    }
};