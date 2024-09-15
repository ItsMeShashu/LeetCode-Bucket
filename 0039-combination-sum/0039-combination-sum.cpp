class Solution {
public:
    void func(int idx, vector<int>& candidates, int n, int sum, int target, vector<int>& vec, vector<vector<int>>& result) {
        if (idx == n) {
            if (sum == target) result.push_back(vec);
            return;
        }
        // INCLUDE..................
        if ((sum + candidates[idx]) <= target) {
            sum += candidates[idx];
            vec.push_back(candidates[idx]);
            func(idx, candidates, n, sum, target, vec, result);
            sum -= candidates[idx];
            vec.pop_back();
        }
        // Exculde................
        func(idx+1, candidates, n, sum, target, vec, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> vec;
        func(0, candidates, n, 0, target, vec, result);
        return result;
    }
};