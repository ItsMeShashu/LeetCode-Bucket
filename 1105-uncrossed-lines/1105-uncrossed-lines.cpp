class Solution {
public:

    int func(vector<int>& nums1, vector<int>& nums2, int n, int m, int i, int j, vector<vector<int>> &dp){
        if(i == n || j==m) return 0 ; 

        if(dp[i][j] != -1) return dp[i][j] ; 

        if(nums1[i] == nums2[j]){
            dp[i][j] = 1 + func(nums1, nums2, n, m, i+1, j+1, dp); 
        } 
        else{
            dp[i][j] = max({func(nums1, nums2, n, m, i+1, j, dp), func(nums1, nums2, n, m, i, j+1, dp), dp[i][j]}) ;
        }

        return dp[i][j] ; 
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(); 
        vector<vector<int>> dp(n, vector<int>(m, -1)) ; 
        return func(nums1, nums2, n, m, 0, 0, dp) ; 
    }
};