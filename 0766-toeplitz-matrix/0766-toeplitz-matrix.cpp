class Solution 
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size();
        
        /*
        int next;
        
        for(int i=0; i<m*n; i++) 
        {
            if(i%n==n-1) continue; //for handling rightmost column
            
            next = i+n+1;
            if(next < m*n)
                if(matrix[i/n][i%n] != matrix[next/n][next%n]) return false;
        }
        */
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i-1][j-1] != matrix[i][j]) return false;
            }
        }
        return true;
        
    }
};