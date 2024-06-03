class Solution {
public:
    void reverseString(vector<char>& str) {
        int s = 0;
        int e = str.size() - 1 ;

        while(s < e) {
            swap(str[s], str[e]);
            s++; 
            e-- ; 
        }
    }
};