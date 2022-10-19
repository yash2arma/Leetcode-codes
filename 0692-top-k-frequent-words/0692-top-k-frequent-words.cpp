class Solution 
{
public:
    
    static bool compare(pair<int, string> &a, pair<int, string> &b)
    {
        if(a.first!=b.first) return a.first>b.first;
        else return a.second<b.second;
            
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> mp;
        for(auto it:words)
        {
            mp[it]++;
        }
        
        vector<pair<int, string>> pq;
        
        for(auto it:mp)
        {
            pq.push_back({it.second, it.first});
        }
        
        sort(pq.begin(), pq.end(), compare);
        vector<string> res;
        
        for(int i=0; i<pq.size(); i++)
        {
            if(k!=0)
            {
                res.push_back(pq[i].second);
                k--;
            }
        }
        return res;
    }
};