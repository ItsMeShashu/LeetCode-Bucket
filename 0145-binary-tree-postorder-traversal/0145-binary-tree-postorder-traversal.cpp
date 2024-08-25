/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULL), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> postOrder; 
        if (root == NULL)
            return postOrder;
 
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left != NULL)
                st1.push(curr->left);

            if (curr->right != NULL)
                st1.push(curr->right);
        }

        while (!st2.empty()) {
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }

        return postOrder;
    }
};