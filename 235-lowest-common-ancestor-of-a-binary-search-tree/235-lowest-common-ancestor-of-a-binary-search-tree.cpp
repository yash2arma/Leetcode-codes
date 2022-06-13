/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* LCA;
        
        while(true)
        {
            int value = root->val;
            if(value > p->val && value > q->val)
                root = root->left;
    
            else if(value < p->val && value < q->val)
                root = root->right;
            
            else
            {
                LCA = root;
                break;
            } 
        }
        return LCA;
        
    }
};