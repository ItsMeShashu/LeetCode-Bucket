class Solution {
public:
    string decodeString(string s) {
        string ans ;
        stack<char>st;
     
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                // pop till '[' not came
                while(!st.empty() && st.top()!='[')
                {
                    ans=st.top()+ans;
                    st.pop();
                }
                
                // at this line we have ']' at top so pop it
                if(!st.empty())
                  st.pop();
                  
                // extract digit
                string digits="";
                while(!st.empty() && st.top()>='0' && st.top()<='9')
                {
                    digits=st.top()+digits;
                    st.pop();
                }
                
                // concate the string 
                int num=stoi(digits);
                
                string temp=ans;
                
                for(int i=0;i<num-1;i++)
                    ans+=temp;
                     
                //  push all to stack 
                for(int i=0;i<ans.size();i++)
                    st.push(ans[i]);
                
                // reset ans
                ans="";
            }
            else
              st.push(s[i]);
        }
        
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
      
        return ans;  
    }
};