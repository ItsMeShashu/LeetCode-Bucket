class Solution {
public:

    // static bool comp(pair<char, int>& a, pair<char, int>& b){
    //     return a.second > b.second ;
    // }

    string frequencySort(string s) {
        unordered_map<char, int> mp; 

        for(auto i: s){
            mp[i]++ ;
        }

        vector< pair<char, int> > vec; 
        for(auto it: mp){
            vec.push_back(it); 
        }

        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second ;
        }); //Sorting of a map

        string ans ; 
        for(auto i : vec){
            while(i.second > 0){
                ans += i.first ;
                i.second-- ; 
            }     
        }

        return ans ;
    }

};