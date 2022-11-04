class Solution 
{
public:
    string reverseVowels(string s) 
    {
        set<char> ds = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l=0, r=s.size()-1;
        
        while(l<r)
        {
            while(l<r && !ds.count(s[l])) l++;
            while(l<r && !ds.count(s[r])) r--;
            
            swap(s[l++],s[r--]);
            
        }
        
        return s;
        
        
        
    }
};