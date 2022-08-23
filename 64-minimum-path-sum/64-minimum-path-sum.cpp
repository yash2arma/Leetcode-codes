class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<int> pre(n,0);
        
        for(int i=0; i<m; i++)
        {
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) cur[j]=grid[i][j];
                else
                {
                    int left=INT_MAX, up=INT_MAX;
                    if(i>0) up = grid[i][j] + pre[j];
                    if(j>0) left = grid[i][j] + cur[j-1];
                    cur[j] = min(left, up);
                }
            }
            pre = cur;
        }
        return pre[n-1];
    }
};