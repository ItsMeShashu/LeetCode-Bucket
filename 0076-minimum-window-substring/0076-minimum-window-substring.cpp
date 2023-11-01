class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(m>n || n == 0 || m == 0){
            return ""; 
        }

        vector<int>vec(256, 0); 
        for(int i=0; i<m; i++){
            vec[t[i]]++ ;
        }

        int strt =0, end=0, ansStrt = 0; 
        int minLength = INT_MAX; 
        int count = 0; 

        while(end < n){
            if(vec[s[end]] > 0){
                count++ ;
            }

            vec[s[end]]-- ;
            while(count == m){
                if(minLength > end - strt + 1){
                    minLength = end - strt + 1;
                    ansStrt = strt ;
                }

                vec[s[strt]]++ ;
                if(vec[s[strt]] > 0){
                    count-- ;
                }

                strt++ ;
            }
            end++ ;
        }
        
        if(minLength == INT_MAX){
            return ""; 
        }

        return s.substr(ansStrt, minLength); 
    }
};