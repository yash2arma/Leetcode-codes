class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n = arr.size();
        int l=0, r=n-1;
        int lm=0, rm=0;
        int res=0;
        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                if(arr[l]>=lm)
                {
                    lm = arr[l];
                }
                else
                {
                    res += lm - arr[l];
                }
                l++;
            }
            else
            {
                if(arr[r]>=rm)
                {
                    rm = arr[r];
                }
                else
                {
                    res += rm - arr[r];
                }
                r--;
            }
        }
        return res;

    }
};