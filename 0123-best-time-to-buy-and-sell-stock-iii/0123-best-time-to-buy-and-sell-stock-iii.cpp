class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        //devide 3d matrix into 1d for n and 2d for buy & cap
        vector<vector<int>> after(2, vector<int> (3, 0)), cur(2, vector<int> (3, 0));

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int cap=1; cap<=2; cap++)
                {
                    if(buy)
                    {
                        cur[buy][cap] = max(-prices[i] + after[0][cap], 
                                     0 + after[1][cap]); //take 
                    }
                    else
                    {
                        cur[buy][cap] = max(prices[i] + after[1][cap-1], 
                                    0 + after[0][cap]); //not take 
                    }
                }
            }
            after = cur;
        }

        return after[1][2];

        }
};