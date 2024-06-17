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
    int maxLevelSum(TreeNode* root) {
        int maxiSum = INT_MIN;
        queue<TreeNode*> q; 
        q.push(root); 
        int maxLevel = 0;
        int level = 0; 

        while(!q.empty()){
            int sz = q.size(); 
            int sum = 0; 
            level++ ;
            for(int i=0; i<sz; i++){
                TreeNode* front = q.front(); 
                q.pop(); 

                sum += front->val ;
                if(front->left) q.push(front->left); 
                if(front->right) q.push(front->right);
            }
            if(sum > maxiSum){
                maxiSum = sum; 
                maxLevel = level;
            }
        }

        return maxLevel; 
    }
};