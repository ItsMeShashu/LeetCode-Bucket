class Solution {
public:
    void backtrack(int start, vector<int>& comb,vector<vector<int>>& res, int n, int k) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int num = start; num <= n; num++) {
            comb.push_back(num);
            backtrack(num + 1, comb, res, n, k);
            comb.pop_back();
        }
    } 

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;

        backtrack(1, comb, res, n, k);
        return res;        
    }   
};