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
    bool isSymmetric(TreeNode* root) 
    {    

        return !root || check(root->left, root->right); 
    }
    
    bool check(TreeNode* left, TreeNode* right)
    {
        //if anyone of them is NULL check whethere they are equal
        if(left==NULL || right==NULL) 
            return left==right;
        
        //if both the values are not equal return false
        if(left->val != right->val)
            return false;
        
        //traverse leftsub tree and rightsub tree simultaneously
        return check(left->left, right->right)
            && check(left->right, right->left);
    }
};