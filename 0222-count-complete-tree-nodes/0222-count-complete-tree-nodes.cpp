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
    int countNodes(TreeNode* root) 
    {
        if(root==NULL) return 0;
        
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        
        //when left and right height are equal return 2^h-1
        if(lh==rh) return (1<<lh) - 1; //<<(right shift operation)
        
        //otherwise traverse left and right subtree
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int findLeftHeight(TreeNode* node)
    {
        int height = 0;
        //until node==NULL
        while(node)
        {
            node = node->left;
            height++;
        }
        return height;
    }
    
    int findRightHeight(TreeNode* node)
    {
        int height = 0;
        //until node==NULL
        while(node)
        {
            node = node->right;
            height++;
        }
        return height;
    }
};