class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        
        long long n=nums.size();
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)//3 sum
            {
                long long low=j+1;
                long long high=n-1;
                long long sum=(long long)target-(long long)nums[i]-(long long)nums[j];
                
                while(low<high)
                {
                    if(nums[low]+nums[high]==sum)
                    {
                        vector<int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[low]);
                        quad.push_back(nums[high]);
                        v.push_back(quad);
                        while(low<high && nums[low]==nums[low+1])low++;
                         while(low<high && nums[high]==nums[high-1])high--;
                        
                        
                        low++;
                        high--;
                        
                    }
                    else if(nums[low]+nums[high]<sum) low++;
                    else high--;
                }
                while(j+1<n && nums[j+1]==nums[j] )j++;
                
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
            
            
        }
        return v;
        
    }
};