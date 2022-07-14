/*class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k = n-k%n;
        
        vector<int> temp;
        for(int i=k; i<n; i++)
            temp.push_back(nums[i]);
        
        int r=n-1;
        int l=k-1;
        while(l>=0)
        {
            nums[r--] = nums[l--];
        }
        
        for(int i=0; i<=r; i++)
            nums[i] = temp[i];
    
    }
};
*/


class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> temp(n);  
        for(int i=0; i<n; i++)
            temp[(i+k)%n] = nums[i];
        nums = temp;
    
    }
};

