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
    int minCameraCover(TreeNode* root) 
    {
        int cam = 0;
        int miniCam = cover(root, cam);
        
        if(miniCam==-1)
            cam++;
        
        return cam;
    }
    
    int cover(TreeNode* root, int &cam)
    {
        if(root==NULL) return 1;
        
        int left = cover(root->left, cam);
        int right = cover(root->right, cam);
        
        if(left==-1 || right==-1)
        {
            cam++;
            return 0;
        }
        
        else if(left==0 || right==0)
            return 1;
        
        return -1;
    }
        
};