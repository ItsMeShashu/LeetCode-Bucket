//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // int ans = -1;
        // for(int i = 0; i < n; i++){
            
        //     bool isCeleb = true;
        //     // check the whole row to be 0
        //     for(int c = 0; c < n; c++){
        //         isCeleb &= (M[i][c] == 0);
        //     }
            
        //     // check the whole col to be 1
        //     for(int r = 0; r < n; r++){
        //         if(r == i) continue;
        //         isCeleb &= (M[r][i] == 1);
        //     }
            
        //     if(isCeleb){
        //         ans = i;
        //         break;
        //     }
            
        // }
        // return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends