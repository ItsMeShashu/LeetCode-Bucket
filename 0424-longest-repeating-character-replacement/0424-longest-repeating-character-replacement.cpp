class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0 ;
        int maxFreq = INT_MIN ; 
        int maxLen = 0 ;
        unordered_map<char, int> mp; 

        int n = s.length() ; 
        while(j<n){
            mp[s[j]]++ ; 
            maxFreq = max(maxFreq, mp[s[j]]) ; 
            int windowSize = j-i+1 ;  
            int minElemToChange = windowSize - maxFreq ; 

            if(minElemToChange > k){
                mp[s[i]]-- ; 
                i++ ; 
            }

            int newWindow = j-i+1 ; 
            maxLen = max(maxLen, newWindow) ; 
            j++ ; 
        }

        return maxLen ; 
    }
};