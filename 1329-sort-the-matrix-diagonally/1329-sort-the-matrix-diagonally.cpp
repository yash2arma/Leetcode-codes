class Solution 
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int row=mat.size(), col=mat[0].size();
        vector<int> dia;
        int x, y, i;
        
        for(int c=col-1; c>=0; c--)
        {
            x=0, y=c;
            while(x<row && y<col)
            {
                dia.push_back(mat[x++][y++]);
            }
            sort(begin(dia), end(dia));
            
            x=0, y=c, i=0;
            while(i<dia.size())
            {
                mat[x++][y++] = dia[i++];
            }
            dia.clear();
        }
        
        for(int r=1; r<row; r++)
        {
            x=r, y=0;
            while(x<row && y<col)
            {
                dia.push_back(mat[x++][y++]);
            }
            sort(begin(dia), end(dia));
            
            x=r, y=0, i=0;
            while(i<dia.size())
            {
                mat[x++][y++] = dia[i++];
            }
            dia.clear();
        }
        return mat;
        
    }
};