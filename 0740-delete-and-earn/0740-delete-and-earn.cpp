class Solution {
public:
    unordered_map<int, int> memo;

int solve(int idx, const vector<int>& unq, const unordered_map<int, int>& mp) {
    // Base case: no elements left
    if (idx < 0) return 0;
    if (idx == 0) return unq[0] * mp.at(unq[0]);
    
    // If result is already computed, return it
    if (memo.find(idx) != memo.end()) return memo[idx];
    
    // Case 1: Take the current element
    int take = unq[idx] * mp.at(unq[idx]);
    if (idx > 0 && unq[idx - 1] == unq[idx] - 1) {
        take += solve(idx - 2, unq, mp);
    } else {
        take += solve(idx - 1, unq, mp);
    }
    
    // Case 2: Skip the current element
    int skip = solve(idx - 1, unq, mp);
    
    // Store the result in memo table
    memo[idx] = max(take, skip);
    
    // Return the result for current index
    return memo[idx];
}

int deleteAndEarn(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    
    // Count the occurrences of each number
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    
    vector<int> unq;
    for (const auto& it : mp) {
        unq.push_back(it.first);
    }
    
    // Sort unique numbers
    sort(unq.begin(), unq.end());
    
    // Clear the memoization map
    memo.clear();
    
    // Start solving from the last element of the unique list
    return solve(unq.size() - 1, unq, mp);
}
};