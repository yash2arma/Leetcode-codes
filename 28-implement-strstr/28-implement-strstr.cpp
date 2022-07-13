class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int hs=haystack.size();
        int ns=needle.size();
        if(ns==0) return 0;
        int j=0;
        
        for(int i=0; i<hs-ns+1; i++)
        {
            if(haystack[i]==needle[j])
            {
                int new_i=i, new_j=j;
                while(haystack[new_i]==needle[new_j] && new_i<hs && new_j<ns)
                {
                    new_i++;
                    new_j++;
                }
                if(new_j>=ns)
                    return i;
                    
            }
        }
        return -1;
        
    }
};