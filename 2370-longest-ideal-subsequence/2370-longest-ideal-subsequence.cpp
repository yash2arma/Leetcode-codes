/*class Solution 
{
public:
    
    void help(int i, string s, int k, string temp, int &maxi, map<string, int> &dp)
    {
        if(i>=s.length())
        {
            maxi = temp.size()>maxi ? temp.size() : maxi;
            return;
        }
           
        temp += s[i];
        cout<<temp<<" ";
        help(i+1, s, k, temp, maxi, dp);
        temp.substr(0, temp.size());
        cout<<temp<<endl;
        help(i+1, s, k, temp, maxi, dp);

    }
    int longestIdealString(string s, int k) 
    {
        string temp="";
        int maxi = 0;
        map<string, int> dp;
        help(0, s, k, temp, maxi, dp);
        return maxi;       
    }
};*/

class Solution 
{
private:
    int solve(int ind, string &s, int prev, int k, vector<vector<int>> &dp) 
    {
        if(ind == -1) 
        {
            return 0;
        }
        
        if(dp[ind][prev] != -1)
            return dp[ind][prev];
        
        int take = 0;
        int ch = s[ind] - 'a' + 1;
        
        if (prev == 0 or abs(ch - prev) <= k) 
        {
            take = solve(ind - 1, s, ch, k, dp) + 1;
        }
        
        int notTake = solve(ind - 1, s, prev, k, dp);
        return dp[ind][prev] = max(take, notTake);
    }
public:
    
    int longestIdealString(string s, int k) 
    {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1)); // 27 because space for 26 alphabets and one more for '0';
        
        return solve(n - 1, s, 0, k, dp);
    }
};