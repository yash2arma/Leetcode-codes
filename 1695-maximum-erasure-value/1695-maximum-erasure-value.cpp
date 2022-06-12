class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int l=0, r=0;
        vector<int> sum_arr;
        sum_arr.push_back(0);
        int sum=0, score=nums[0];
        for(auto it:nums)
        {
            sum += it;
            sum_arr.push_back(sum);
        }
        
        unordered_map<int, int> mp; //store element and index
        while(r<nums.size())
        {
            if(mp.find(nums[r]) != mp.end()) l=max(l, mp[nums[r]]+1);
            mp[nums[r]] = r;
            score = max(score, sum_arr[r+1]-sum_arr[l]);
            r++;
        }
        return score;
        
    }
};