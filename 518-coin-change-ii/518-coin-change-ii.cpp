class Solution 
{
public:
    int change(int value, vector<int>& coins) 
    {
        int n=coins.size();
        vector<int> pre(value+1, 0), cur(value+1, 0);
    
        for(int t=0; t<=value; t++)
        {
            pre[t] = t%coins[0]==0;
        }

        for(int i=1; i<n; i++)
        {
            for(int t=0; t<=value; t++)
            {
                int np = pre[t];
                int p=0;
                if(coins[i] <= t)
                    p = cur[t-coins[i]];
                cur[t] = p + np;
            }
            pre = cur;
        }
        return pre[value];

    }
};