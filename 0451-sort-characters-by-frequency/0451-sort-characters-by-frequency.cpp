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

        vector< pair<char, int> > vec(mp.begin(), mp.end()); 

        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second ;
        }); //Sorting of a vec

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