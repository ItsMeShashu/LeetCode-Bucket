class Solution {
public:

int solve(int idx, const vector<int>& unq, const unordered_map<int, int>& mp, vector<int> &dp) {
    if (idx < 0) return 0;
    if (idx == 0) return (unq[0] * mp.at(unq[0]));
    
    if (dp[idx] != -1)  return dp[idx];

    int take = unq[idx] * mp.at(unq[idx]);
    if (idx > 0 && unq[idx - 1] == unq[idx] - 1) {
        take += solve(idx - 2, unq, mp, dp);
    } 
    else {
        take += solve(idx - 1, unq, mp, dp);
    }

    int skip = solve(idx - 1, unq, mp, dp);
    
    dp[idx] = max(take, skip);
    return dp[idx];
}

int deleteAndEarn(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    
    vector<int> unq;
    for (auto it : mp) {
        unq.push_back(it.first);
    }

    sort(unq.begin(), unq.end());
    
    vector<int> dp(unq.size(), -1) ; 
    
    return solve(unq.size() - 1, unq, mp, dp);
}
};