class Solution 
{
public:
    /*bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size(), n=matrix[0].size();
        int low,mid,high;

        for(int i=0; i<m; i++)
        {
            if(target<=matrix[i][n-1])
            {
                low=0, high=n-1;
                while(low<=high)
                {
                    mid = low+(high-low)/2;
                    
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target) low = mid+1;
                    else high = mid-1;
                }
            }
        }
        return false; 
    }
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size(), r = 0, c = n - 1;
        while (r < m && c >= 0) 
        {
            if (matrix[r][c] == target) 
            {
                return true;
            }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};