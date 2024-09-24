#include<bits/stdc++.h>

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st ; 
        for(int num : arr1){
            string str = to_string(num) ; 
            string prefix ;
            for(char ch: str){
                prefix += ch ; 
                st.insert(prefix) ; 
            }
        }

        int maxLen = 0 ; 

        for(int num : arr2){
            string str = to_string(num) ; 
            string prefix ;
            for(char ch: str){
                prefix += ch ; 
                if(st.count(prefix) > 0){
                    maxLen = max(maxLen, (int)prefix.length()) ; 
                } 
            }
        }

        return maxLen ; 
    }
};