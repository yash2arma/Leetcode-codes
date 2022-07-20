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
    /*TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        
        TreeNode* root = new TreeNode(root1->val + root2->val);
        
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        
        return root;        
    }*/
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() && !q2.empty())
        {
            TreeNode* h1 = q1.front(); q1.pop();
            TreeNode* h2 = q2.front(); q2.pop();
            
            h1->val = h1->val + h2->val;
            
            if(h1->left && h2->left)
            {
                q1.push(h1->left);
                q2.push(h2->left);
            }
            
            else if(h2->left)
                h1->left = h2->left;
            
            if(h1->right && h2->right)
            {
                q1.push(h1->right);
                q2.push(h2->right);
            }
            
            else if(h2->right)
                h1->right = h2->right;

        }
        
        return root1;        
    }
};