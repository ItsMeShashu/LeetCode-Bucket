class Solution {
public:
    int minLength(string s) {
        stack<char> st ;
        for(char ch: s){
            if(st.empty()){
                st.push(ch) ;
                // continue; 
            }  
            else if(st.top() == 'A' && ch == 'B'){
                st.pop(); 
                // continue; 
            }
            else if(st.top() =='C' && ch =='D'){
                st.pop() ; 
                // continue; 
            } 
            else 
                st.push(ch) ; 
        }

        return st.size(); 
    }
};