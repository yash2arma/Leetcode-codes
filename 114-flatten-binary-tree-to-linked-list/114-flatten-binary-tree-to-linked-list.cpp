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

/*
class Solution {
    TreeNode* prev = NULL;
public:
    
    //use recursion
    void flatten(TreeNode* root) 
    {

        if(root==NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev = root;

    }
};
*/

/*class Solution {
public:
    
    //use iterative approach
    void flatten(TreeNode* root) 
    {
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* node = st.top(); st.pop();
            
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            
            if(!st.empty())
            {
                node->right = st.top();
            }
            node->left = NULL;
        }
    }
};
*/

/*
class Solution {
public:
    
    //use iterative approach
    void flatten(TreeNode* root) 
    {
        TreeNode* cur = root;
        
        while(cur)
        {
            if(cur->left)
            {
                TreeNode* prev = cur->left;
                while(prev->right)
                    prev = prev->right;
                
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
*/

class Solution 
{  
public:
    
    void flatten(TreeNode* root)
    {
        if(!root) return ;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* root = st.top(); st.pop();
            
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
            
            if(!st.empty())
            {
                root->right = st.top();
            }
            root->left = NULL;
        }
    }
};
