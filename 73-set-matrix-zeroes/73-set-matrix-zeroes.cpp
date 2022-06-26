/*class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> row(m, INT_MIN); //row vector track in which row there is 0 
        vector<int> col(n, INT_MIN); //col vector track in which col there is 0
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=0; //mark row=0;
                    col[j]=0; //mark col=0;
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(row[i]==0 || col[j]==0) //when we find any row/col 0
                    matrix[i][j]=0; //mark matrix with 0
            }
        }                
        
    }
                        
};
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int r=matrix.size(), c=matrix[0].size(), col0=1;// it means there is no 0 in 1st col
        
        for(int i=0; i<r; i++)
        {
            if(matrix[i][0]==0) col0=0;
            for(int j=1; j<c; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=r-1; i>=0; i--)
        {
            for(int j=c-1; j>=1; j--)
            {
                if(matrix[i][0]==0 or matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col0==0) matrix[i][0]=0;
        }
        
        
    }
};
        
