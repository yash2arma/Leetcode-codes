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
class Solution 
{
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1) 
        {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        
        
        queue<TreeNode*> q;
        q.push(root);
        depth--;
        
        while(!q.empty() || depth!=0)
        {
            depth--;
            int sz = q.size();
            
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front(); q.pop();
                
                if(depth==0)
                {
                    TreeNode* new_left = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = new_left;
                    
                    TreeNode* new_right = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = new_right;
                }
                
                else
                {
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
            }
        }
        
        return root;
        
    }
};