class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0;  
        long long res = 0;    
        int n = s.length();
        
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') ones++;  
            
            else if (s[j] == '0') res += ones;  
        }
        
        return res;
    }
};