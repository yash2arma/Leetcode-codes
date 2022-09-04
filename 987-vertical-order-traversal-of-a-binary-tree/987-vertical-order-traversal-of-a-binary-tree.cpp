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
    /*vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> nodes; //ds-{vertical, {level, node->val}}
        queue<pair<TreeNode*, pair<int,int>>> todo; //{Node, {vertical, level}};
        todo.push({root, {0,0}});
        
        while(!todo.empty())
        {
            auto p = todo.front(); //p = {node,{x,y}}
            todo.pop();
            
            TreeNode* node = p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(node->val);
            
            //vertical decrease and level increase for left move
            if(node->left) todo.push({node->left, {x-1, y+1}}); 
            //vertical increase and level increase for right move
            if(node->right) todo.push({node->right, {x+1, y+1}}); 
        }
        
        vector<vector<int>> ans;
        for(auto p: nodes)
        {
            vector<int> row;
            
            //q carries all vertical nodes
            for(auto q: p.second) 
            {
                row.insert(row.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(row);
        }
        return ans;
    }
    */
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0,0}});
        
        while(!q.empty())
        {
            auto frnt = q.front();
            q.pop();
            
            TreeNode* node = frnt.first;
            int x=frnt.second.first, y=frnt.second.second;
            
            nodes[x][y].insert(node->val);
            
            if(node->left)
                q.push({node->left, {x-1, y+1}});
            if(node->right)
                q.push({node->right, {x+1, y+1}});
        }
        
        
        vector<vector<int>> ans;
        
        for(auto p:nodes)
        {
            vector<int> row;
            for(auto q:p.second)
            {
                row.insert(row.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};