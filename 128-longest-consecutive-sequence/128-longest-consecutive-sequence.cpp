class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1;
        int pre = nums[0];
        int cnt = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == pre) continue;
            if(nums[i] == pre+1)
            {
                cnt++;
                pre = pre+1;
            }
            else
            {
                cnt = 1;
                pre = nums[i];
                    
            }
            longest = max(longest, cnt);
        }
        return longest;
        
        return longest;
    }
};