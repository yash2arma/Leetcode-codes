class Solution 
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size();
        
        if(m==1 || n==1) return true;
        int next;
        
        for(int i=0; i<m*n; i++) 
        {
            if(i%n==n-1) continue;
            
            next = i+n+1;
            if(next < m*n)
                if(matrix[i/n][i%n] != matrix[next/n][next%n]) return false;
        }
        return true;
        
    }
};