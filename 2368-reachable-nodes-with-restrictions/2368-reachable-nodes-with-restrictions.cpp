class Solution 
{
public:
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) 
    {
        unordered_set<int> s(res.begin(), res.end());
        vector<int> e[n];
        for(auto it:edges)
        {
            e[it[0]].push_back(it[1]);
            e[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int count=0;
        
        while(!q.empty())
        {
            int node= q.front(); q.pop();
            if(s.count(node)) continue;
            count++;
            for(auto it:e[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
 
        }
        return count;
            
    }
};
