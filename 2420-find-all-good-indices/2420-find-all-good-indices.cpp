class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        vector<int> pre(n, 1), nex(n, 1), res;
        
        for(int i=1; i<n; i++)
        {
            if(nums[i]<=nums[i-1])
                pre[i] += pre[i-1];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]<=nums[i+1])
                nex[i] += nex[i+1];
        }
        
        for(int i=k; i<n-k; i++)
        {
            if(pre[i-1]>=k && nex[i+1]>=k)
                res.push_back(i);
        }
        return res;
    }
};