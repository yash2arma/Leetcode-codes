class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> vis(n+1, 0);
        
        for(auto it:nums)
            vis[it]++;
        
        int duplicate, miss;
        
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==2) duplicate = i;
            if(vis[i]==0) miss = i;
        }
        
        return {duplicate, miss};
    }
};