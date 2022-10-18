class Solution {
public:
    int maxProfit(int k, vector<int> &prices) 
    {
        int n=prices.size();
        vector<int> after(2*k+1, 0), cur(2*k+1, 0);

        for(int i=n-1; i>=0; i--)
        {
            for(int transNo=2*k-1; transNo>=0; transNo--)
            {
                if(transNo%2==0) //buy
                {
                    cur[transNo] = max(-prices[i] + after[transNo+1], 
                                0 + after[transNo]);
                }
                else
                {
                    cur[transNo] = max(prices[i] + after[transNo+1], 
                                0 + after[transNo]);
                }
            }
            after = cur;
        }
        return cur[0];
    }

};