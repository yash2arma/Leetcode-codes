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
    bool isValidBST(TreeNode* root) 
    {
        return validBST(root, LONG_MIN, LONG_MAX);      
    }
    
    bool validBST(TreeNode* node, long lower, long higher)
    {
        if(!node) return true;
        
        if(node->val <= lower || node->val >= higher) return false;
        
        return validBST(node->left, lower, node->val) &&
            validBST(node->right, node->val, higher);
    }
};