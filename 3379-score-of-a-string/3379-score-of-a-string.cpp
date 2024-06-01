class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length(); 
        int i = 1; 
        int sum = 0; 

        while(i < n){
            sum += abs(int(s[i]) - int(s[i-1]) ); 
            i++ ;
        }

        return sum; 
    }
};