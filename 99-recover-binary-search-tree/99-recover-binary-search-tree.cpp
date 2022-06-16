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

//Brute-Force Approach:
/*class Solution {
public:
    vector<int> v;
    int i=0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void check(TreeNode* root){
        if(!root) return;
        check(root->left);
        if(v[i]!=root->val) swap(v[i],root->val);
        i++;
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end());
        check(root);
    }
};
*/

class Solution {
private:
    TreeNode *prev, *first, *middle, *last;

private:
    void inorder(TreeNode* root)
    {
        if(!root) return;
        
        inorder(root->left);
        
        if(prev!=NULL && (root->val < prev->val))
        {
            //if this is first violation, then mark these two nodes as
            //first and middle
            if(first==NULL) 
            {
                first = prev;
                middle = root;
            }
            
            //if this is second violation, then mark this node as last
            else last = root;
        }
        
        prev = root;
        inorder(root->right);
    }
public:
    
    void recoverTree(TreeNode* root) 
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
        
    }
};