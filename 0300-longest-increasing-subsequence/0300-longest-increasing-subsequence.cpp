class Solution {
public:

    // int recFunc(int n, vector<int> arr, int currIdx, int prevIdx){
    //     if(currIdx == n){
    //         return 0; 
    //     }
        
    //     // INCLUDE but we also need to check condition before including
    //     int include = 0; 
    //     if(prevIdx == -1 || arr[currIdx] > arr[prevIdx]){
    //         include = 1 + recFunc(n, arr, currIdx + 1, currIdx);  
    //     }
        
    //     // EXCLUDE
    //     int exclude = 0 + recFunc(n, arr, currIdx+1, prevIdx);
        
    //     return max(include, exclude); 
    // }
    
    int memFunc(int n, vector<int>& arr, int currIdx, int prevIdx, vector< vector<int> > &dp){
        if(currIdx == n){
            return 0; 
        }
        
        // we write prev+1 bcoz initially prev have value -1 so to not get error we write prev+1
        if(dp[currIdx][prevIdx+1] != -1){
            return dp[currIdx][prevIdx+1] ;
        }
        
        // INCLUDE but we also need to check condition before including
        int include = 0; 
        if(prevIdx == -1 || arr[currIdx] > arr[prevIdx]){
            include = 1 + memFunc(n, arr, currIdx + 1, currIdx, dp);  
        }
        
        // EXCLUDE
        int exclude = 0 + memFunc(n, arr, currIdx+1, prevIdx, dp);
        
        return dp[currIdx][prevIdx+1] = max(include, exclude); 
    }
    
    int lengthOfLIS(vector<int>& arr) {
        //  return recFunc(n, arr, 0, -1);
        int n = arr.size(); 
        vector< vector<int> > dp(n, vector<int>(n+1, -1)); 
        return memFunc(n, arr, 0, -1, dp); 
    }
};