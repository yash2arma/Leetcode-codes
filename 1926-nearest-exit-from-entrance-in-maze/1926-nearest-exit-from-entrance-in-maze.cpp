/*
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
*/

class Solution {
public:
    int dirx[4] = { -1, 0, 0, 1 };
    int diry[4] = { 0, 1, -1, 0 };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<array<int, 3>> q; // {i, j, steps}
        // push the starting point (i, j) with initial step 0
        q.push({entrance[0], entrance[1], 0});
        // BFS
        while (!q.empty()) {
            auto [i, j, steps] = q.front(); q.pop();
            // handle exit condition, we can exit if
            // 1. the current position is not the entrance 
            bool isAtTheEntrance = i == entrance[0] && j == entrance[1];
            // 2. and the current position is at the border
            bool isAtTheBorder = i == 0 || j == 0 || i == m - 1 || j == n - 1;
            if (!isAtTheEntrance && isAtTheBorder) return steps;
            // try for 4 directions
            for (int d = 0; d < 4; d++) {
                int next_i = i + dirx[d];
                int next_j = j + diry[d];
                // check if we can move to (next_i, next_j)
                if (next_i >= 0 && next_j >= 0 && next_i < m && next_j < n && maze[next_i][next_j] == '.') {
                    // if so, we mark the next cell to `+` so that we won't visit it again
                    maze[next_i][next_j] = '+';
                    // add the next position to the queue with steps + 1
                    q.push({next_i, next_j, steps + 1});
                }
            }
        }
        return -1;
    }
};
