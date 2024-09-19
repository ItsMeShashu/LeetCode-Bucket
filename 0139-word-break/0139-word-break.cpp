class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length() ; 
        vector<bool> vec(n+1, false); 
        vec[0] = true; 
        
        for(int i=1; i<=n; i++){
            for(auto word:wordDict){
                int strt = i - word.length(); 
                if(strt >= 0 && vec[strt] == true && s.substr(strt, word.length()) == word){
                    vec[i] = true; 
                    break ; 
                }
            }
        }
        
        return vec[n] ; 
    }
};