class Solution {
public:
    
    //use recursive approach to build unique binary tree.
    //we use the property of preorder(Root-Left-Right), inorder(Left-Root-Right).
    //to construct the tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> inmap;
        for(int i=0; i<inorder.size(); i++)
            inmap[inorder[i]] = i;
        
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);
      
    }
    
    TreeNode* build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &inmap)
    {
        if(ps>pe || is>ie) return NULL;
        
        TreeNode* node = new TreeNode(preorder[ps]);
        int inval = inmap[node->val];
        int leftnodes = inval-is;
        
        node->left = build(preorder, ps+1, ps+leftnodes, inorder, is, inval-1, inmap);
        node->right = build(preorder, ps+leftnodes+1, pe, inorder, inval+1, ie, inmap);
        
        return node;
    }
     
    
    
};



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
public:
    
    //use recursive approach to build unique binary tree.
    //we use the property of preorder(Root-Left-Right), inorder(Left-Root-Right).
    //to construct the tree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int, int> inMap;
        
        //store the index of inorder traversal elements into the hashmap
        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        //call build function that returns root of the created tree 
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        
        return root;       
    }
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                   vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap)
    {
        //when vector gets empty it means we are at leaf node and return NULL.
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        //since we know, first element of preorder is a root
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        //in inorder left part of root is leftsubtree and right part of root is         rightsubtree
        int inRoot = inMap[root->val]; //find root index
        int numLeft = inRoot - inStart; //and how many elements are on the left of it.
        
        //calling left and right node of a root
        root->left = build(preorder, preStart+1, preStart+numLeft,
                          inorder, inStart, inRoot-1, inMap);
        root->right = build(preorder, preStart+numLeft+1, preEnd,
                           inorder, inRoot+1, inEnd, inMap);
        
        return root;
    }
    
};

*/