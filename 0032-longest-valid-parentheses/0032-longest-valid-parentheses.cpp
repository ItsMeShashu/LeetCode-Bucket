class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0){
            return 0 ;
        }

        stack<int>st ;
        st.push(-1); 
        int ans = 0;
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i]; 
            
            if(ch == '('){
                st.push(i); 
            }
            else{
                st.pop(); 
                
                if(!st.empty()){
                    ans = max(ans, (i-st.top()) );
                }
                else{
                    st.push(i); 
                }
            }
            
        }
        
        return ans;
    }
};