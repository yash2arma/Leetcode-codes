class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxi=0;
        int cnt = 0;
        for(auto it: nums)
        {
            if(it==1)
                cnt++;
            else
                cnt = 0;
            maxi = max(maxi, cnt);
        }
        return maxi;
        
    }
};