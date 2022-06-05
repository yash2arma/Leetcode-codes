class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        //sort nums to get all values in ascending order  
        sort(nums.begin(), nums.end());
        int n=nums.size(), count=0, flag=0, mini=INT_MAX;
        
    
        //iterate through the nums
        for(int j=0; j<n; j++)
        {
            //when flag is 0 
            if(!flag)
            {
                flag=1; //mark flag=1 which shows new subsequence started
                mini = nums[j];  //since nums is in ascending order, mini will be at first index of new subsequence
                count++;
            }

            //when difference is greater than k we need to start new subsequence
            if(abs(nums[j]-mini) > k)
            {
                //re-assign flag=0, mini, and decrement j, to consider it in new subsequence
                flag=0; 
                mini = INT_MAX; 
                j--;
            }
        }
            
        return count;
    }
};