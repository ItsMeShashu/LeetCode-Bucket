class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char> st;
        string ans ; 
        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};