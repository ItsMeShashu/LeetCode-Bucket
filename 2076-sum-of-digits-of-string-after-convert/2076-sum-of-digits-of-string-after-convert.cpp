class Solution {
public:
    int getLucky(string s, int k) {
        int ans ; 
        string str ; 
        int n = s.length() ; 
        for(int i=0; i<n; i++){
            str = str + to_string(s[i] - 'a' + 1); 
        }
        int temp ; 
        while(k--){
            temp = 0 ; 
            for(char ch: str){
                temp += ch - '0' ; 
            }
            str = to_string(temp) ;
        }

        return temp ;         
    }
};