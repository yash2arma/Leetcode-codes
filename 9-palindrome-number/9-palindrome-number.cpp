class Solution {
public:
    bool isPalindrome(int x) 
    {
        
        if(x<0 || (x!=0) && x%10==0 ) return false;
        
        int rn = 0;
        
        while(x>rn)
        {
            rn = rn*10 + x%10;
            x = x/10;
        }
        
        return (x==rn || rn/10 == x);
    }
};


