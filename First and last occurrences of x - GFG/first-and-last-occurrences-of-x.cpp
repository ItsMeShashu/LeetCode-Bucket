//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int firstOcc(int nums[], int n, int key){
        int ans = -1 ;
        int s=0;
        int e=n-1;
        
        while(s<=e){
            int mid = s + (e-s)/2 ;
            if(nums[mid] == key){
                ans = mid ;
                e = mid - 1 ;
            }
            else if(nums[mid] < key){
                s = mid + 1 ;
            }
            else{
                e = mid - 1 ;
            }
        }
        return ans ;
    }

    int lastOcc(int nums[], int n, int key){
        int ans = -1 ;
        int s=0;
        int e=n-1;
        // int mid = s + (e-s)/2 ;
        while(s<=e){
            int mid = s + (e-s)/2 ;
            if(nums[mid] == key){
                ans = mid ;
                s = mid + 1 ;
            }
            else if(nums[mid]  < key){
                s = mid + 1 ;
            }
            else{
                e = mid - 1 ;
            }
        }
        return ans ;
    }
    
    
    vector<int> find(int nums[], int n , int x )
    {
        // code here
        vector<int>ans ;
        ans.push_back(firstOcc(nums,n,x));
        ans.push_back(lastOcc(nums,n,x));
        
        return ans ;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends