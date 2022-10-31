class Solution {
public:
    /*
    int lengthOfLIS(vector<int>& nums) 
    {
        const int n=nums.size();
        vector<int> dp(n, 1);
        
        for(int i{1}; i<n; i++)
        {
            for(int j{0}; j<i; j++)
            {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    */
    
    //binary search
    int lengthOfLIS(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        int len=1;

        for(int i=1; i<n; i++)
        {
            if(arr[i] > temp.back())
            {
                len++;
                temp.push_back(arr[i]);
            }

            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
        return len;
    }

};

