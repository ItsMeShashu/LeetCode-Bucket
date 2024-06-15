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
    TreeNode* solve(vector<int> in, vector<int> post, int &index, int inStrt, int inEnd,map<int,int>& nodetoindex, int n)
    {
        if(index<0 || inStrt > inEnd) return NULL;

        int element = post[index--];
        TreeNode* root = new TreeNode(element);
        int position = nodetoindex[element];
        
        root->right=solve(in, post, index, position+1, inEnd, nodetoindex, n);
        root->left=solve(in,post,index,inStrt,position-1,nodetoindex,n);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postIndx = n-1;
        
        map<int,int> nodetoindex;
        for(int i=0;i<n;i++){
            nodetoindex[inorder[i]]=i;
        }

        TreeNode* ans=solve(inorder, postorder, postIndx, 0, n-1, nodetoindex, n);

        return ans;
    }
};