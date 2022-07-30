class Solution {
public:
    vector<int> cal_freq(string s)
    {
        vector<int> freq(26,0);
        for(auto it:s)
        {
            freq[it-'a']++;
        }
        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<int> max_freq(26,0);
        vector<string> res;
        
        for(auto it:words2)
        {
            vector<int> freq = cal_freq(it);
            
            for(int i=0; i<26; i++)
            {
                max_freq[i] = max(freq[i], max_freq[i]);
            }
        }
        
        int flag;
        for(auto it:words1)
        {
            flag=0;
            vector<int> freq = cal_freq(it);
            
            for(int i=0; i<26; i++)
            {
                if(freq[i] < max_freq[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) res.push_back(it);
        }

        return res;
        
    }
};