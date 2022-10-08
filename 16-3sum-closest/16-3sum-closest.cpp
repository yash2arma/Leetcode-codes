class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int closest = INT_MAX;
        int ans;
        for(int i=0; i<n; i++)
        {
            int a=nums[i];
            int low=i+1, high=n-1;
            
            while(low<high)
            {
                int sum = a+nums[low]+nums[high];
                
               if(abs(sum-target) < closest)
                {
                    closest = abs(sum-target);
                    ans = sum;
                }
                
                if(sum == target) break;
                else if(sum > target) high--;
                else low++;
                
            }
        }
        return ans;
        
    }
};