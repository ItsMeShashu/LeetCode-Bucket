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

    void func(TreeNode* root, int currMax, int &ans){
        if(root == NULL) return ; 

        if(root->val >= currMax){
            ans++; 
            currMax = root->val; 
        }
        func(root->left, currMax, ans);
        func(root->right, currMax, ans);
    }


    int goodNodes(TreeNode* root) {
        int currMax = root->val; 
        int ans = 0; 

        func(root, currMax, ans); 

        return ans ;
    }
};