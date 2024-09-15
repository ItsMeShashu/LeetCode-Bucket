class Solution {
public:

    void func(int num, int target, int k, vector<int>& vec, vector<vector<int>>& result) {
        if (vec.size() == k) {
            if(target == 0) result.push_back(vec);
            return;
        }

        for (int i = num; i <=9; i++) {
            if (num > target)
                break;

            vec.push_back(i);
            target -= i ; 
            func(i + 1, target, k, vec, result);
            target += i ; 
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> vec;
        func(1, n, k, vec, result);

        return result;
    }
};