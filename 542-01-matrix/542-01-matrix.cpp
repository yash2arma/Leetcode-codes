class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        vector<int> dir = {0, 1, 0, -1, 0};
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0) q.push({i, j});
                else mat[i][j] = -1; // Marked as not processed yet!
            }
        }
        
        while(!q.empty())
        {
            auto [r,c] = q.front(); q.pop();
            
            for(int i=0; i<4; i++)
            {
                int cur_r = r+dir[i];
                int cur_c = c+dir[i+1];
                
                if(cur_r<0 || cur_r==m || cur_c<0 || cur_c==n || mat[cur_r][cur_c]!=-1)
                    continue;
                
                mat[cur_r][cur_c] = 1 + mat[r][c];
                q.push({cur_r, cur_c});
            }
        }

        
        return mat;
    }
    
};
