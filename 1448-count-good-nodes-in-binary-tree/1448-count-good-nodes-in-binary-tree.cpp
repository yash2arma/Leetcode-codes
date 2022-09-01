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
    void dfs(TreeNode* node, int &count, int maxi)
    {
        if(!node) return;
        if(node->val >= maxi)
        {
            maxi = node->val;
            count++;
        }
        
        dfs(node->left, count, maxi);
        dfs(node->right, count, maxi);
    }
    
    int goodNodes(TreeNode* root) 
    {
        int count=0;
        dfs(root, count, INT_MIN);
        return count;
    }
};