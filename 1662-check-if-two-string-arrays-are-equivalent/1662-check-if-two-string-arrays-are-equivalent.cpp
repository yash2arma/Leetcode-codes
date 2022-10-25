class Solution 
{
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string a, b;
        
        for(auto it:word1)
            a += it;
        
        for(auto it:word2)
            b += it;
        
        if(a.size() != b.size()) return false;
        
        for(int i=0; i<a.size(); i++)
            if(a[i]!=b[i]) return false;
        
        return true;
        
    }
};