class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int m=mat.size(), n=mat[0].size();
        
        if(m*n != r*c) return mat;
        
        vector<vector<int>> new_mat(r, vector<int>(c, 0));
        
        for(int i=0; i<m*n; i++)
        {
           new_mat[i/c][i%c] = mat[i/n][i%n];
        }
        
        return new_mat;        
    }
};