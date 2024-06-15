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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL || (root->right == NULL && root->left == NULL)){
            return root;
        }
        
        TreeNode* leftInvert = invertTree(root->left); 
        TreeNode* rightInvert = invertTree(root->right);

        root->right = leftInvert; 
        root->left = rightInvert ;

        return root; 
    }
};