class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> row(m, INT_MIN);
        vector<int> col(n, INT_MIN);
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(row[i]==0 || col[j]==0)
                    matrix[i][j]=0;
            }
        }                
        
    }
                        
};
        
