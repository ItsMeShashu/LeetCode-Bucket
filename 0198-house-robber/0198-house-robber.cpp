class Solution {
public:
//APPROACH 1..............................
    // int rob(vector<int>& arr) {
    //     int n = arr.size();
    //     if (n == 1)
    //         return arr[0];

    //     arr[1] = max(arr[1], arr[0]);
    //     for (int i = 2; i < n; i++) {
    //         arr[i] = max(arr[i] + arr[i - 2], arr[i - 1]);
    //     }
    //     return arr[n - 1];
    // }

// APPROACH 2: DP APPROACH.........................................
    int f(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == nums.size()-1) return nums[ind]; 
        if (ind >= nums.size()) return 0; // no house to rob

        if (dp[ind] != -1) return dp[ind]; 

        int take = nums[ind] + f(ind + 2, nums, dp);

        int notTake = f(ind + 1, nums, dp);

        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};