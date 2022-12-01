class Solution 
{
public:
    bool halvesAreAlike(string s) 
    {
        int l=0, r=s.size()-1;
        int a=0, b=0;
        
        while(l<r)
        {
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u' || 
               s[l]=='A' || s[l]=='E' || s[l]=='I' || s[l]=='O' || s[l]=='U')
                a++;
            
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u' || 
               s[r]=='A' || s[r]=='E' || s[r]=='I' || s[r]=='O' || s[r]=='U')
                b++;
            
            l++;
            r--;
        }
        return a==b;
        
    }
};