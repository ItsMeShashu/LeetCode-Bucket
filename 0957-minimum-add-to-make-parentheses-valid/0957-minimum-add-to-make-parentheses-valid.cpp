class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st ;
        int ans = 0 ;

        for(int i=0; i<s.length(); i++){
            char ch = s[i]; 
            if(ch == '('){
                st.push(ch); 
            }
            else{
                if(!st.empty()){
                    st.pop(); 
                }
                else{
                    ans++ ;
                }
            }
        }

        ans = ans + st.size(); 
        return (ans); 
    }
};