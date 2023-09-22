//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        if(n==1)
            return "1"; 
        if(n==2)
            return "11";

        string str = "11";

        for(int i=3; i<=n; i++ ){
            string temp ;
            str = str + "$" ;
            int count = 1;
            for(int j=1; j<str.length();j++){
                if(str[j-1]== str[j]){
                    count++ ;
                }
                else{
                    temp = temp + to_string(count) ;
                    temp = temp + str[j-1];
                    count = 1 ;
                }
            }

            str = temp ;
        } 

        return str ;
        
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends