class Solution 
{
public:
    
    //1. Memoization
    /*
    int f(int i, vector<int>& prices, int buy, vector<vector<int>> &dp)
    {
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int profit=0;
        
        if(buy) //buying stock
        {
            profit = max(-prices[i] + f(i+1, prices, 0, dp), 0 + f(i+1, prices, 1, dp));
            
        }
        else //selling stock
        {
            profit = max(prices[i] + f(i+1, prices, 1, dp), 0 + f(i+1, prices, 0, dp));
        }
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return f(0, prices, 1, dp);
    }
    */
    
    //2. Tabulation 
    /*
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        dp[n][1] = dp[n][0] = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy <= 1; buy++)
            {
                int profit=0;
                if(buy) //buying stock
                {
                    profit = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);

                }
                else //selling stock
                {
                    profit = max(prices[i] + dp[i+1][1], 0 + dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    */
    
    //3. Space Optimization - 1d vector
    /*
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int> cur(2, 0), after(2, 0);
        
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy <= 1; buy++)
            {
                int profit=0;
                if(buy) //buying stock
                {
                    profit = max(-prices[i] + after[0], 0 + after[1]);

                }
                else //selling stock
                {
                    profit = max(prices[i] + after[1], 0 + after[0]);
                }
                cur[buy] = profit;
            }
            after = cur;
        }
        return after[1];
    }
    */
    
    //4. Space Optimization - 4 variable
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size(), aheadBuy=0, aheadNotBuy=0, curBuy, curNotBuy;
        
        for(int i=n-1; i>=0; i--)
        {
            curBuy = max(-prices[i] + aheadNotBuy, 0 + aheadBuy);

            curNotBuy = max(prices[i] + aheadBuy, 0 + aheadNotBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
                
        }
        return aheadBuy;
    }
};