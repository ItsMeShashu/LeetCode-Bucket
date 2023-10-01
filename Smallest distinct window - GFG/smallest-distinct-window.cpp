//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int n=str.size();
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;i++)
            mp[str[i]]++;
            
        int min_window=mp.size();
        
        for(int i=0;i<n;i++)
            mp.erase(str[i]);
            
        int l=0,ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            mp[str[i]]++;
            while(l<=i && mp.size() == min_window){
                ans=min(ans,i-l+1);
                mp[str[l]]--;
                if(mp[str[l]]==0){
                    mp.erase(str[l]);
                }
                l++;
            }
        }
        if(ans==INT_MAX)
            return -1;
        else    
            return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends