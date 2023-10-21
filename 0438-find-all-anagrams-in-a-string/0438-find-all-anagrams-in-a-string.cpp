class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(s.length() < p.length()) 
            return {}; 
        
        vector<int>sVec(26, 0);
        vector<int>pVec(26, 0);
        vector<int>ans; 
        for(int i=0; i<p.length(); i++){
            sVec[s[i] - 'a']++;
            pVec[p[i] - 'a']++;
        }
        if(sVec == pVec)
            ans.push_back(0);

        for(int i=p.length(); i<s.length(); i++){
            sVec[s[i] - 'a']++;
            sVec[s[i - p.length()] - 'a']--;

            if(sVec == pVec)
                ans.push_back(i+1-p.length());
        } 

        return ans;    
    }
};