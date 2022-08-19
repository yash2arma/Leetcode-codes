/*

//We can use recursion but it takes too much time and we get TLE
//So, we implement dynamic programming with recursion/dp
class Solution {
public:
    
    int findPath(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        //boudary and obstacle condition
        if(r>=grid.size() || c>=grid[0].size() || grid[r][c]==1) return 0;
        
        //if we reach right bottom, we get 1 path and return it
        if(r==grid.size()-1 && c==grid[0].size()-1) return 1;
        
        //if path is already store in dp we return it
        if(dp[r][c]!=-1) return dp[r][c];
        
        //calculate the no. of path by moving down and right and return it
        //and store it into the dp
        return dp[r][c]= (findPath(r+1, c, grid, dp) + findPath(r, c+1, grid, dp));
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1)); //create mxn matrix dp and initialize it with -1
        return findPath(0,0, obstacleGrid, dp); calling the function to find no. of unique path
    }
};
*/

//Tabulation:-
/*
//Use bottom-up approach to save the auxiliary space taken by recursion
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        //if top-left corner has value 1 it means there in no path
        if(obstacleGrid[0][0]==1) return 0;
        
        //store no. of rows and columns
        int m = obstacleGrid.size(), n=obstacleGrid[0].size();
        
        //create dp and initialize it with 0
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        //base condition for bottom-up approach
        dp[0][0] = 1;
        
        //traverse through the matrix
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //if we are at top-left corner(0,0) we don't have left(0,-1) and up(-1,0,) cell
                //so to avoid this condition we continue at 0,0
                if(i==0 && j==0) continue;
                
                //if there is no obstacle
                if(obstacleGrid[i][j]==0)
                {
                    int up=0, left=0;

                    //store top cell value
                    if(i-1 >=0)
                        up = dp[i-1][j];

                    //store left cell value
                    if(j-1 >=0)
                        left = dp[i][j-1];
                
                    //and add them for current cell to get no. of unique paths 
                    //to reach at current position
                    dp[i][j] = up + left;
                }
            }
        }
        //return dp at (m-1, n-1) that will be the no. of unique paths
        //to reach at bottom right corner
        return dp[m-1][n-1];
         
    }
};
*/

//Space Optimization
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& a) 
    {
        if(a[0][0]==1) return 0;
        int m=a.size(), n=a[0].size();
        vector<int> pre(n, 0);
        
        for(int i=0; i<m; i++)
        {
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++)
            {
                if(a[i][j]==1) cur[j]=0;
                else if(i==0 && j==0) cur[j]=1;
                else
                {
                    int up=0, left=0;
                    if(i>0) up = pre[j];
                    if(j>0) left=cur[j-1];
                    cur[j]=up+left;
                }
                
            }
            pre = cur;
        }
        return pre[n-1];
    }
};