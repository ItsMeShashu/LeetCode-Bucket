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

    void inorder(TreeNode* root, vector<int> &in){
        if(root == NULL) return;
        inorder(root->left, in); 
        in.push_back(root->val);
        inorder(root->right, in); 
    }

    TreeNode* func(vector<int>& nums, int s, int e){
        if(s>e){
            return NULL;
        }

        int mid = (s+e)/2 ; 
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = func(nums, s, mid-1);
        newNode->right = func(nums, mid+1, e);

        return newNode; 
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in; 
        inorder(root, in); 
        int n = in.size();  

        return func(in, 0, n-1); 
    }
};