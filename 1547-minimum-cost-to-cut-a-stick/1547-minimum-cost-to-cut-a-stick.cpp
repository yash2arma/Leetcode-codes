class Solution {
public:
    
    /*
    int mincost(int start, int end, vector<int>& cuts, int cuts_start, int cuts_end)
    {
        if(cuts_start>cuts_end)
            return 0;
        
        if(dp[cuts_start][cuts_end]!=-1)
            return dp[cuts_start][cuts_end];
        
        int minimum = INT_MAX;
        for(int i=cuts_start; i<=cuts_end; i++)
            minimum = min(minimum, (end-start)+mincost(start, cuts[i], cuts, cuts_start, i-1)+mincost(cuts[i], end, cuts, i+1, cuts_end));
        
        return dp[cuts_start][cuts_end] = minimum;
    }
    
    int minCost(int n, vector<int>& cuts) {

        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return mincost(0, n, cuts, 0, cuts.size()-1);
    }
    */
    
    int minCost(int n, vector<int>& cuts) 
    {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

        for(int i=c; i>=1; i--)
        {
            for(int j=1; j<=c; j++)
            {
                if(i>j) continue;
                int mini=INT_MAX;
                for(int ind=i; ind<=j; ind++)
                {
                    int cost = cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
        }
};