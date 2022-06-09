class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) 
    {
        int s=0, e=nums.size()-1;
        while(s<e)
        {
            if(nums[s]+nums[e]==tar) break;
            
            else if(nums[s]+nums[e]>tar) e--;
            
            else s++;
        }
        return {s+1, e+1};           
    }
};