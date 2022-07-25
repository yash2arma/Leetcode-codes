class Solution {
public:
    int lower_bound(vector<int>& nums, int tar)
    {
        int low=0, high=nums.size()-1;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(nums[mid] < tar)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int start = lower_bound(nums, target);
        int end = lower_bound(nums, target+1)-1;
        
        if(start<nums.size() && nums[start]==target)
            return {start, end};
        else
            return {-1,-1};
    }
};