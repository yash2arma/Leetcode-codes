class Solution 
{
public:
    
    //1. Memoization
    /*
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e8;

        if(i==r-1)
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int dj1=-1; dj1<=1; dj1++)
        {
            for(int dj2=-1; dj2<=1; dj2++)
            {
                int x1=j1+dj1, x2=j2+dj2;
                if(j1==j2) maxi = max(maxi, grid[i][j1] + f(i+1, x1, x2, r, c, grid, dp));
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, x1, x2, r, c, grid, dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r=grid.size(), c=grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
        return f(0, 0, c-1, r, c, grid, dp);
    }
    */
    
    
    //2. Tabulation
    /*
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r=grid.size(), c=grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, 0)));

        for(int j1=0; j1<c; j1++)
        {
            for(int j2=0; j2<c; j2++)
            {
                if(j1==j2) dp[r-1][j1][j2]=grid[r-1][j1];
                else dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
            }
        }

        //all possible ways
        for(int i=r-2; i>=0; i--)
        {
            for(int j1=0; j1<c; j1++)
            {
                for(int j2=0; j2<c; j2++)
                {
                    int maxi=INT_MIN;
                    for(int dj1=-1; dj1<=1; dj1++)
                    {
                        for(int dj2=-1; dj2<=1; dj2++)
                        {
                            int ans=0;
                            int x1=j1+dj1, x2=j2+dj2;

                            if(j1==j2) ans=grid[i][j1];
                            else ans=grid[i][j1] + grid[i][j2];

                            if(x1>=0 && x1<c && x2>=0 && x2<c)
                                ans += dp[i+1][x1][x2];
                            else
                                ans += -1e8;

                             maxi = max(maxi, ans);  
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][c-1];
    }
    */
    
    //3. Space Optimization
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>> front(c, vector<int> (c, 0));
        vector<vector<int>> cur(c, vector<int> (c, 0));

        for(int j1=0; j1<c; j1++)
        {
            for(int j2=0; j2<c; j2++)
            {
                if(j1==j2) front[j1][j2]=grid[r-1][j1];
                else front[j1][j2]=grid[r-1][j1]+grid[r-1][j2];
            }
        }

        //all possible ways
        for(int i=r-2; i>=0; i--)
        {
            for(int j1=0; j1<c; j1++)
            {
                for(int j2=0; j2<c; j2++)
                {
                    int maxi=INT_MIN;
                    for(int dj1=-1; dj1<=1; dj1++)
                    {
                        for(int dj2=-1; dj2<=1; dj2++)
                        {
                            int ans=0;
                            int x1=j1+dj1, x2=j2+dj2;

                            if(j1==j2) ans=grid[i][j1];
                            else ans=grid[i][j1] + grid[i][j2];

                            if(x1>=0 && x1<c && x2>=0 && x2<c)
                                ans += front[x1][x2];
                            else
                                ans += -1e8;

                             maxi = max(maxi, ans);  
                        }
                    }
                    cur[j1][j2] = maxi;
                }
            }
            front = cur;
        }
        return front[0][c-1];

    }
};