class Solution 
{
public:
    
    //1. Memoization
    /*
    int f(int i, int buy, int &n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        if(buy)
            return dp[i][buy] = max(-prices[i] + f(i+1, 0, n, prices, dp), f(i+1, 1, n, prices, dp));
        
        return dp[i][buy] = max(prices[i] + f(i+2, 1, n, prices, dp), f(i+1, 0, n, prices, dp));
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, n, prices, dp);        
    }
    */
    
    //2. Tabulation
    /*
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        
        for(int i=n-1; i>=0; i--)
        {
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]); //for buy

            dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]); //for sell
        }
        return dp[0][1];        
    }
    */
    
    //3. Space Optimization
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int> cur(2, 0), front1(2, 0), front2(2, 0);
        
        for(int i=n-1; i>=0; i--)
        {
            cur[1] = max(-prices[i] + front1[0], front1[1]); //for buy

            cur[0] = max(prices[i] + front2[1], front1[0]); //for sell
            
            front2 = front1;
            front1 = cur;
        }
        return front1[1];        
    }
    
};