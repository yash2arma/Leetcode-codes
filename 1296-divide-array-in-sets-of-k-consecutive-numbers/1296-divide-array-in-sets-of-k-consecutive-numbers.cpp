class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> left;
        
        for(auto it:nums) left[it]++;
        
        for(auto it:nums)
        {
            if(left[it]==0) continue;
            left[it]--;
            
            for(int i=1; i<k; i++)
            {
                if(left[it+i]>0) left[it+i]--;
                else    return false;
            }
        }
        return true;
        
        
    }
};