class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        // vector<int> ans ; 
        for (int i = 0; i < n; i++) {
            if (haystack[i] == needle[0]) {
                bool match = true;

                for (int j = 1; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }

                // if (match == true)  ans.push_back(i+1); 
                if (match == true) return i; 
            }
        }

        // if(ans.size()) return ans; 
        // else return -1; 
        return -1; 
    }
};