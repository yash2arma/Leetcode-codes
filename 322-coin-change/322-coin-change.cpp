class Solution {
public:
    //It is just like Unbounded knapsack problem
    int coinChange(vector<int>& coins, int amount) 
    {
        //define no. of coins and dp matrix of rows=no. of coins and column= total amount 
        int n = coins.size(); 
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 1e5)); 
        
        //i represent coin value
        for(int i=0; i<=n; i++)
        {
            //j represent amount to be reach
            for(int j=0; j<=amount; j++)
            {
                //if amount value is 0 then we need 0 coins 
                if(j==0) 
                    dp[i][j] = 0;
                
                //if we have 0 value coin then we need infinite coins to reach amount
                else if(i==0)  
                    dp[i][j] = 1e5;
                
                //if coin value is greater than amount needed then we use exclusion case
                //exclusion case - go one level up and copy paste the solution
                else if(coins[i-1]>j) 
                    dp[i][j] = dp[i-1][j];
                
                //if we are able to take current coin then we find mini. of inclusion or exclusion case
                //inclusion case - we add 1 to the dp since we use the coin and in the same level we find other coin (j-coins[i-1]) which can cover the remaining amount
                else
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
        return dp[n][amount]>1e5-1 ? -1 : dp[n][amount];           
    }
};