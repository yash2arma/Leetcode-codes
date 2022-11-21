class Solution 
{
public:
    
    int f(int i, int j, vector<vector<char>>& maze, vector<int>& entrance, int dir, vector<vector<vector<int>>> &dp)
    {
        if(i<0 || j<0 || i>=maze.size() || j>=maze[0].size() || maze[i][j]=='+' || maze[i][j]=='-')
            return 1e5;
        
        if((i!=entrance[0] || j!=entrance[1]) && (i==0 || i==maze.size()-1 || j==0 || j==maze[0].size()-1)) return 0;
        
        if(dir!=-1 && dp[i][j][dir]!=-1) return dp[i][j][dir];
        
        maze[i][j] = '-';
        int minSteps = 1 + min({f(i-1, j, maze, entrance, 0, dp), f(i, j+1, maze, entrance, 1, dp), f(i+1, j, maze, entrance, 2, dp), f(i, j-1, maze, entrance, 3, dp)});
        maze[i][j] = '.';
        
        if(dir!=-1)
            dp[i][j][dir] = minSteps;
        
        return minSteps;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        vector<vector<vector<int>>> dp(maze.size()+1, vector<vector<int>> (maze[0].size()+1, vector<int> (4, -1)));
        int res = f(entrance[0], entrance[1],  maze, entrance, -1, dp);
        return res >= 1e5 ? -1 : res;
    }
};

