class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size(), aheadBuy=0, aheadNotBuy=0, curBuy, curNotBuy;
        
        for(int i=n-1; i>=0; i--)
        {
            curBuy = max(-prices[i] + aheadNotBuy, 0 + aheadBuy);

            curNotBuy = max(prices[i] + aheadBuy - fee, 0 + aheadNotBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
                
        }
        return aheadBuy;
        
    }
};