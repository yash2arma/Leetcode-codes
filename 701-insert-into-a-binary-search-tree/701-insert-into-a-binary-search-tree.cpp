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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        //root is NULL return node with value val
        if(!root) return new TreeNode(val);
        TreeNode* cur = root;
        
        while(true)
        {
            //if value of current node is lesser than val move to right child
            if(cur->val <= val)
            {
                //if right child is not NULL move on it
                if(cur->right != NULL) cur=cur->right;
                
                //if right child is NULL assign new node of value val to it and break
                else 
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            
            //if value of current node is greater than val move to left child
            else
            {
                //if left child is not NULL move on it
                if(cur->left != NULL) cur=cur->left;
                
                //if left child is NULL assign new node of value val to it and break
                else 
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};