class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp ;
        int n = s.length() ;
        int i = 0, j=0; 
        int maxLen = 0;
        int maxFreq = INT_MIN;
        while(j<n){
            mp[s[j]]++ ;
            maxFreq = max(maxFreq, mp[s[j]]); 

            int windowSize = j-i+1; 
            int elemsToChange = windowSize - maxFreq ; //No. of elemnts which need to change in that window

            if(elemsToChange > k){
                mp[s[i]]-- ;
                i++ ;
            }
            int newWindow = j-i+1 ;
            maxLen = max(maxLen, newWindow) ;
            j++ ;
        } 

        return maxLen; 
    }
};