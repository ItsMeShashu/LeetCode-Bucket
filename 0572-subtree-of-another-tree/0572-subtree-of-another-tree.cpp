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

    bool isSame(TreeNode* r, TreeNode* sr){
        if(r == NULL && sr == NULL) return true ; 
        else if(r==NULL || sr == NULL || r->val != sr->val) return false ; 

        bool left = isSame(r->left, sr->left) ;  
        bool right = isSame(r->right, sr->right) ;

        return (left && right) ;   
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true ;
        if(root == NULL) return false ; 

        if(root->val == subRoot->val){
            if(isSame(root, subRoot)) return true ; 
        }

        return ( isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)  ) ; 
    }
};