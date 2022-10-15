class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        int mod=1e9+7;
        vector<int> pint, ans;
        
        for(int i=0; i<32; i++)
        {
            if((n & 1<<i) != 0) pint.push_back(1<<i);
        }
        
        for(auto it:queries)
        {
            int i=it[0];
            long p = pint[i++];
            while(i <= it[1])
                p = (p*pint[i++])%mod;
            ans.push_back(p);
        }
        return ans;
        
    }
};