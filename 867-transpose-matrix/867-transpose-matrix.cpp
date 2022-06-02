class Solution 
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        //create new matrix of rows = columns of given matrix
        //and columns = rows of given matrix
        int c=matrix.size(), r=matrix[0].size();
        int temp=0;
        vector<vector<int>> trans(r, vector<int> (c, 0));
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
               trans[j][i] = matrix[i][j];
            }
        }
        return trans;
    }
};