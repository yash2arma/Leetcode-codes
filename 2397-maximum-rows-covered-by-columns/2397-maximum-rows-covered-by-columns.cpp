class Solution 
{
public:
    void help(int idx, int count, int &r, int &c, vector<int> vis, int &maxi, vector<vector<int>>& mat)
    {
        if(idx==c or count==0)
        {
            int cnt=0;
            for(int i=0; i<r; i++)
            {
                bool check=true;
                for(int j=0; j<c; j++)
                {
                    if(mat[i][j]==1 && vis[j]==0)
                    {
                        check=false;
                        break;
                    }
                }
                if(check) cnt++;
            }
            maxi = max(maxi, cnt);
            return;
        }
        
        vis[idx]=1;
        help(idx+1, count-1, r, c, vis, maxi, mat);
        
        vis[idx]=0;
        help(idx+1, count, r, c, vis, maxi, mat);
    }
    
    int maximumRows(vector<vector<int>>& mat, int cols) 
    {
        int r=mat.size(), c=mat[0].size();
        
        vector<int> vis(c);
        int maxi=INT_MIN;
        help(0, cols, r, c, vis, maxi, mat);
        return maxi;
    }
};