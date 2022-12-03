class Solution {
public:
    /*
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
    */
    
    string frequencySort(string s) 
    {
        unordered_map<char, int> mp;
        for(auto it:s)
            mp[it]++;
        
        priority_queue<pair<int, char>> pq;
        for(auto it:mp)
            pq.push(make_pair(it.second, it.first));
        
        string res="";
        while(!pq.empty())
        {
            int n=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            res.append(n, c);
        }
        return res;
    }
};