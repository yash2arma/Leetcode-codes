class Solution 
{
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n = pref.size();
        int prex=0;
        
        for(int i=1; i<n; i++)
        {
            prex ^= pref[i-1];
            pref[i] = prex^pref[i];
        }
        return pref;
    }
};

