class Solution 
{
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> res;
        int sum=0;
        
        for(auto it:nums) if(it%2==0) sum += it;
        
        for(auto it:queries)
        {
            if(nums[it[1]]%2==0) sum -= nums[it[1]];
            nums[it[1]] += it[0];
            if(nums[it[1]]%2==0) sum += nums[it[1]];
            res.push_back(sum);
        }
        return res;       
    }
};