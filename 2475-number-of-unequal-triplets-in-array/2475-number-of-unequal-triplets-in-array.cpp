/*
class Solution 
{
public:
    int unequalTriplets(vector<int>& nums) 
    {
        int cnt=0, n=nums.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if(nums[i] != nums[j] and nums[i] != nums[k] and nums[j] != nums[k])
                        cnt++;
                }
            }
        }
        return cnt;
        
    }
};
*/
    
class Solution 
{
    public:
        int unequalTriplets(vector<int>& nums) 
        {
            int count = 0, prev = 0, nxt = nums.size();
            unordered_map<int, int> frequency;

            for (int n : nums) 
                frequency[n]++;

            for (auto[n, freq] : frequency)
            {
                nxt -= freq;
                count += prev * freq * nxt;
                prev += freq;
            }
            return count;
        }
};