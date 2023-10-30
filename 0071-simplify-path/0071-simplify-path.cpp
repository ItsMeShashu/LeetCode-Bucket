class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st; 
        int n = path.length() ;
        
        for(int i=0; i<n; i++){
            string str; 

            if(path[i] == '/'){
                continue;
            }

            while(path[i] != '/' && i<n){
                str += path[i++]; 
            }

            if(str == ".."){
                if(!st.empty()){
                    st.pop(); 
                }
            }
            else if(str == "."){
                continue; 
            }
            else{
                st.push(str); 
            }
        }

        string res; 
        while(!st.empty()){
           res = "/" + st.top() + res ; 
           st.pop(); 
        }

        if(res.length() > 0){
            return res; 
        }
        else{
            return "/"; 
        }
    }
};