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
    
    unordered_map<int, int> mp;
    int ans=0;
    
    void help(TreeNode* node)
    {
        if(node==NULL) return ;
        
        mp[node->val]++;
        
        if(node->left==NULL && node->right==NULL)
        {
            int cnt=0;
            for(auto it:mp)
                if((it.second%2) == 1) cnt++;
            
            if(cnt<=1) ans++;
        }
        
        help(node->left);
        help(node->right);
        
        mp[node->val]--;
    }
    
    int pseudoPalindromicPaths(TreeNode* root) 
    {
        help(root);
        return ans;
    }
};