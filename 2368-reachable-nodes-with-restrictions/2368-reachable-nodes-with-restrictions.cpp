/*
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
*/

class Solution {
public:
	int dfs(int node,vector<int>&vis,vector<int>adj[]){
		if(vis[node]) return 0;
		vis[node] = 1;
		int res = 0;
		for(auto edge:adj[node]) if(!vis[edge]) res+=dfs(edge,vis,adj);
			return res+1;
	}

	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
		vector<int>vis(n,0);
		for(auto x:restricted) vis[x] = 1;
		vector<int>adj[n];
		for(auto node:edges) adj[node[0]].push_back(node[1]),adj[node[1]].push_back(node[0]);
		return dfs(0,vis,adj);
	}
};