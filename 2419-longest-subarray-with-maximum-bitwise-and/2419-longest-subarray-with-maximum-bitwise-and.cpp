//Please upvote if it helps :)
/*Approach : In this problem, we just need to find the maximum number and count its maximum contiguous sequence that will be the answer*/

class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxi_val=0;
        
        for(auto it:nums)
            maxi_val = max(maxi_val, it);
        
        int cnt=0, maxi=1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==maxi_val)
                cnt++;          
            else 
                cnt=0;
            
            maxi = max(maxi, cnt);
                
        }
        return maxi;
    }
};