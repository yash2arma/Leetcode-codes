//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
  
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        queue<pair<int, int>> q;
        q.push({row,col});
        vis[row][col]=1;
        int n=grid.size(), m=grid[0].size();
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c= q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; j++)
                {
                    int nrow=r+i, ncol=c+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends