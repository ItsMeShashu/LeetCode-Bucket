class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length() ; 
        if(n == 0) return 0 ; 
        unordered_map<char, int> mp ; 
        int maxLen = INT_MIN ; 
        int j = 0; 
        for(int i=0; i<n; i++){
            mp[s[i]]++ ; 

            while(j<i && mp[s[i]] > 1 ){
                mp[s[j]]-- ;
                j++ ;
            }

            maxLen = max(maxLen, i-j+1 ) ; 
        }

        return maxLen ; 
    }
};