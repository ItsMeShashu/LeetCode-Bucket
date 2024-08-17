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

    vector<TreeNode*> func(int s, int e, vector<vector<vector<TreeNode*>>> &dp){
        vector<TreeNode*> ans ; 
        if(s > e){
            ans.push_back(NULL); 
            return ans ; 
        }
        if(!dp[s][e].empty()) return dp[s][e] ; 

        for(int i=s; i<=e; i++){
            vector<TreeNode*> left = func(s, i-1, dp);
            vector<TreeNode*> right = func(i+1, e, dp);

            for(auto lt: left){
                for(auto rt: right){
                    TreeNode* root = new TreeNode(i) ; 

                    root->left = lt ; 
                    root->right = rt ;
                    ans.push_back(root) ; 
                }
            }
        }

        dp[s][e] = ans; 
        return dp[s][e] ;  
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
        return func(1, n, dp) ; 
    }
};