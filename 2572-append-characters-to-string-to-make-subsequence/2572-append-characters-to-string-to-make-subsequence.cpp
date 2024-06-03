class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j=0; 
        int n = s.length(); 
        int m = t.length(); 

        while(i < n && j < m){
            if(s[i] == t[j]){
                i++; 
                j++ ;
            }
            else{
                i++ ;
            }
        }
        
        return (m-j); 
    }
};