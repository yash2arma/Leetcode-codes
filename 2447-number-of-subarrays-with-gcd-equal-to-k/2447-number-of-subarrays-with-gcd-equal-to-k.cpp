class Solution 
{
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {
        
        int n=nums.size();
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            int gcd = nums[i];
            for(int j=i; j<n; j++)
            {
                if(nums[j]%k!=0) break;
                
                gcd = __gcd(gcd, nums[j]);
                if(gcd==k) ans++;
            }
        }
        
        
        return ans;
        
    }
};