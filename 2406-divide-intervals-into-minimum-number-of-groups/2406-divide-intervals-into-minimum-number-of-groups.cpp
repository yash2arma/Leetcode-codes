class Solution 
{
public:
    /*
    int minGroups(vector<vector<int>>& intervals) 
    {
        map<pair<int, int>, int> mp;
        
        for(auto it:intervals)
            mp[{it[0], it[1]}]++;
        
        int cnt=0;
        int x, y, fl;
        while(!mp.empty())
        {
            fl=0;
            for(auto it:mp)
            {
                if(fl==0)
                {
                    x=it.first.first;
                    y=it.first.second;
                    mp[it.first]--;
                    fl=1;
                }
                else
                {
                    if(it.first.first > y)
                    {
                        y=it.first.second;
                        mp[it.first]--;
                    }
                }
                if(mp[it.first]==0) mp.erase(it.first);
            }
            cnt++;
        }
        return cnt;
    }
    */
    int minGroups(vector<vector<int>>& ints) 
    {
        sort(begin(ints), end(ints));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &i : ints) {
            if (!pq.empty() && pq.top() < i[0])
                pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};