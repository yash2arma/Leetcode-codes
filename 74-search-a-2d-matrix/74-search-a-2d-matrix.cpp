class Solution {
public:
    //use binary search to find the target
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int r=matrix.size(), c=matrix[0].size();
        //use low, high and consider the matrix as 1d vector
        int low=0, high=r*c-1;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            //to find the row(use '/') and column(use '%')
            if(matrix[mid/c][mid%c] == target) return true;
            
            else if(matrix[mid/c][mid%c] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};