class Solution {
public:
    int minDeletions(string s) 
    {
        int freq[26] = {0};
        
        for(auto c : s)
            freq[c-'a']++;
        
        
        sort(freq, freq+26);
        
        int del = 0, prev;
        
        for(int i=24; i>=0; i--)
        {
            if(freq[i]==0) break;
            
            if(freq[i] >= freq[i+1])
            {
                prev = freq[i];
                freq[i] = max(0, freq[i+1]-1);
                del += (prev - freq[i]);
            }
        }
        return del;
    }
};