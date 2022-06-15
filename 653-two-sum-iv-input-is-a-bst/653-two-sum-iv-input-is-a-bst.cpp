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

class BSTIterator{
private:    
    stack<TreeNode*> st;
    //reverse = true - before(back);
    //reverse = false - next(front);
    bool reverse = true;
    
    void pushAll(TreeNode* node)
    {
        while(node)
        {
            st.push(node);
            if(reverse) node = node->right; //before-back
            else node = node->left; //next-front
        }
    }
    
public:
    BSTIterator(TreeNode* node, bool isReverse)
    {
        reverse = isReverse;
        pushAll(node);
    }
    
    int next()
    {
        TreeNode* top = st.top();
        st.pop();
        
        if(reverse) pushAll(top->left);//before-back
        else pushAll(top->right);//next-front
        
        return top->val;       
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) 
    {
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int left = l.next(); //for next_front
        int right = r.next(); //for before_back
        
        while(left<right)
        {
            if(left+right==k) return true;
            
            else if(left+right<k) left = l.next();
            
            else right = r.next();
        }
        
        return false;       
    }
};