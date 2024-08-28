class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        int n = S.length() ;
        if(n == 0) return 0 ;
        unordered_map<char, int> mp ;
        int i = 0;
        int j = 0;
        int maxLen = INT_MIN ;
        
        while(j < n){
            mp[S[j]]++ ;
            
            while(mp[S[j]] > 1 && i<j){
                mp[S[i]]--;
                i++; 
            }
            
            maxLen = max(maxLen, j-i+1); 
            j++ ; 
        }
        
        return maxLen;
    }
};