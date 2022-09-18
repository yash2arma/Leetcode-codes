class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n = arr.size(), left=0, right=n-1;
        int left_max=0, right_max=0, res=0;
        
        while(left<=right)
        {
            if(arr[left]<=arr[right])
            {
                if(arr[left]>=left_max) left_max = arr[left];
                
                else res += left_max - arr[left];

                left++;
            }
            else
            {
                if(arr[right]>=right_max) right_max = arr[right];
                
                else res += right_max - arr[right];
                
                right--;
            }
        }
        return res;

    }
};