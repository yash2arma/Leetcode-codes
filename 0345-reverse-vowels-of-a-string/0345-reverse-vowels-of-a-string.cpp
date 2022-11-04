class Solution 
{
public:
    string reverseVowels(string s) 
    {
        vector<char> ds;
        
        for(auto it:s)
        {
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
                ds.push_back(it);
        }
        
        reverse(ds.begin(), ds.end());
        for(int i=s.size()-1; i>=0; i--)
        {
            char it=s[i];
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
            {
                s[i]=ds.back();
                ds.pop_back();
            }
            
        }
        
        return s;
        
        
        
    }
};