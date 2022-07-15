class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int z=0, i=0;
        while(i<nums.size() && z<nums.size())
        {
            if(nums[z]==0)
            {
                i=z+1;
                while(i<nums.size())
                {
                    if(nums[i]!=0) break;
                    i++;
                }
                if(i<nums.size())
                    swap(nums[z], nums[i]);
            }
            z++;
        }
    }
};