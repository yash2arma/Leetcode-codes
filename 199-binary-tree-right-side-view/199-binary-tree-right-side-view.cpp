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
/*class Solution {
public:
    void rightview(TreeNode* node,int level, vector<int> &ans )
    {
        if(!node) return;
        
        if(level == ans.size())
            ans.push_back(node->val);
        
        if(node->right) rightview(node->right, level+1, ans);
        if(node->left) rightview(node->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        rightview(root, 0, ans);
        return ans;
    }
};
*/


class Solution {
public:
   
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> right_view;
        if(root==NULL) return right_view;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front(); q.pop();
                if(i==0)
                {
                    right_view.push_back(node->val);
                }
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return right_view;
    }
};