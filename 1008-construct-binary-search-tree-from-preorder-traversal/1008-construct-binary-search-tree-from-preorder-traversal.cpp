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
//Naive Approach:
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i=1; i<preorder.size(); i++)
        {
            int node = preorder[i];
            TreeNode* curr = root;
            
            while(true)
            {
                if(node < curr->val)
                {
                    if(curr->left)
                        curr = curr->left;
                    else
                    {
                        curr->left = new TreeNode(node);
                        break;
                    }
                }
                
                else
                {
                    if(curr->right)
                        curr = curr->right;
                    else
                    {
                        curr->right = new TreeNode(node);
                        break;
                    }
                }               
            }
        }
        return root;
    }
};
*/

//Optimal Approach:
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i=0;
        return build(preorder, i, INT_MAX);
    }
    
    TreeNode* build(vector<int> &A, int &i, int bound)
    {
        if(i==A.size() || A[i]>bound) return NULL;
        
        TreeNode* root = new TreeNode(A[i++]);
        
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        
        return root;
    }
};