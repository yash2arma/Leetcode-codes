class Solution 
{    
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            int len = 1;
            int temp = nums[i];
            for(int j =i;j<nums.size()-1;j++)
            {
                if((temp xor nums[j+1])== temp+nums[j+1])
                {
                    temp+=nums[j+1];
                    len++;
                }
                else
                    break;
                    
            }
            ans=max(len,ans);
        }
        return ans;
    }
};