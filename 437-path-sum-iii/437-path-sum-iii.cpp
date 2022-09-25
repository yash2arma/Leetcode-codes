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
    int ans = 0;
    
    void countPath(TreeNode* root, long pre, int target)
    {
        if(root==NULL) return;
        long current = root->val + pre;
        if(current==target) ans++;
        
        //check this path completely
        countPath(root->left, current, target);
        countPath(root->right, current, target);
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        //start first path with root
        if(root)
        {
            countPath(root, 0, targetSum); //pre= 0, to start path from the current node
            //treat left and right as fresh nodes
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        
        return ans;
    }
};