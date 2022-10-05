class Solution 
{
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> rightMin(n+1, INT_MAX);
        
        for(int i=n-1; i>=0; i--)
            rightMin[i] = min(rightMin[i+1], arr[i]);
        
        int leftMax = INT_MIN;
        int cnt=0;
        
        for(int i=0; i<n; i++)
        {
            leftMax = max(leftMax, arr[i]);
            
            if(leftMax <= rightMin[i+1])
                cnt++;               
        }
        return cnt;       
    }
};