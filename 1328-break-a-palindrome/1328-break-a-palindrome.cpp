class Solution 
{
public:
    string breakPalindrome(string pali) 
    {
        int n=pali.size();
        if(n==1) return "";
        
        for(int i=0; i<n/2; i++)
        {
            if(pali[i]!='a')
            {
                if(i==0)
                {
                    pali[i]='a';
                    return pali;
                }
                if(i>0 && pali[i+1]!='a')
                {
                    pali[i]='a';
                    return pali;
                }
                
                if(pali[i+1]=='a')
                {
                    pali[i+1]='b';
                    return pali;
                }
            } 
        }
        pali[n-1]='b';
        return pali;
    }
};