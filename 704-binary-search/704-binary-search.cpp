class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start=0, end=nums.size()-1;
        
        while(start<=end)
        {
            //find mid index and then compare its value with target
            int mid=(start+end)/2;
            
            //if equal return mid
            if(nums[mid] == target) return mid;
        
            //if its value is less than target then initialize start = mid+1
            else if(nums[mid] < target) start = mid+1;
            
            //if its value is greater than target then initializae end=mid-1
            else end = mid-1;
    
        }
        //return -1 since target is not exist
        return -1;
    }
};