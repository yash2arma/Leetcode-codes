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
    void dfs(TreeNode* node, int tar, vector<int> path, vector<vector<int>> &paths)
    {
        if(!node->left && !node->right)
        {
            if(tar-node->val == 0)
            {
                path.push_back(node->val);
                paths.push_back(path);
            }
        }
        
        
        
        if(node->left)
        {
            path.push_back(node->val);
            dfs(node->left, tar-node->val, path, paths);
            path.pop_back();
        }
        if(node->right)
        {
            path.push_back(node->val);
            dfs(node->right, tar-node->val, path, paths);
            path.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if(!root) return {};
        vector<vector<int>> paths;
        dfs(root, targetSum, {}, paths);
        return paths;        
    }
};