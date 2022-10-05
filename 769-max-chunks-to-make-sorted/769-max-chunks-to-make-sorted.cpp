class Solution 
{
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int cnt=0;
        int maxi_ele=INT_MIN;
        
        for(int i=0; i<arr.size(); i++)
        {
            maxi_ele = max(maxi_ele, arr[i]);
                
            if(i==maxi_ele) cnt++;
        }
        return cnt;
 
    }
};