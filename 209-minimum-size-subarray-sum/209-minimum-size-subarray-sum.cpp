class Solution 
{
public:
    int minSubArrayLen(int tar, vector<int>& nums) 
    {
        int l=0, r=0, n=nums.size(), sum=0, len=INT_MAX;
        
        while(r<n)
        {
            sum += nums[r++];
            while(sum >= tar)
            {
                len = min(len, r-l);
                sum -= nums[l++];
            }
        }
        return len==INT_MAX ? 0 : len;
        
    }
};

