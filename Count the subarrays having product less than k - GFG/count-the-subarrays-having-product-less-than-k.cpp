//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        
        if(k == 0){
            return 0;
        }
        
        long long ans = 0 ;
        long long pro = 1;
        int i = 0;
        for(int j = 0; j<n; j++){
            pro = pro * nums[j];

            while(pro >= k && i < j){
                pro /= nums[i];
                i++ ;
            }

            if(pro<k){
                ans += (j-i+1);
            }
        }

        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends