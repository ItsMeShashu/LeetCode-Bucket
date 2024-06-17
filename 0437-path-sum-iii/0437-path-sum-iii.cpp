/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode *root, int target, unordered_map<long long,int> &m, long long &sum, int &ans){
        if(root == NULL) return ;
        
        sum += root -> val;
        if(m.find((sum - target)) != m.end()){
            ans = ans + m[(sum - target)];
        }
        m[sum]++;

        solve(root -> left, target, m, sum, ans);
        solve(root -> right, target, m, sum, ans);
        //BackTrack
        m[sum]--;
        sum -= root -> val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        long long sum = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        solve(root, targetSum, mp, sum, ans);
        return ans;
    }
};