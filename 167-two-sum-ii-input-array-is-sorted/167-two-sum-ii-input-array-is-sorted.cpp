class Solution {
public:
    //Use 2 pointers approach
    //Given array is already sorted
    vector<int> twoSum(vector<int>& nums, int tar) 
    {
        //define start and end pointer
        int s=0, e=nums.size()-1;
        
        //iterate until both pointers reach at the same index
        while(s<e)
        {
            if(nums[s]+nums[e]==tar) break;
            
            else if(nums[s]+nums[e]>tar) e--;
            
            else s++;
        }
        //return the index of s and e added by one
        return {s+1, e+1};           
    }
};