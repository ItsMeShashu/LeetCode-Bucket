/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void deleteNodes(TreeNode* &root, unordered_set<int>& set, vector<TreeNode*>& ans) {
        if (root == NULL) return;

        deleteNodes(root->left, set, ans);
        deleteNodes(root->right, set, ans);

        if (set.find(root->val) != set.end()) {
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);
            root = NULL;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> set;

        for (auto num : to_delete) {
            set.insert(num);
        }
        deleteNodes(root, set, ans);
        if (root != NULL)
            ans.push_back(root);
        return ans;
    }
};