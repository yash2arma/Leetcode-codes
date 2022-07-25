class Solution {
public:
    /*
    bool isPowerOfTwo(int n) 
    {
        while(n)
        {
            if(n==1) return true;
            if(n%2==1) return false;
            n = n/2;
        }
        return false;
    }
    */
    
    /*
    bool isPowerOfTwo(int n) 
    {
        if(n==0) return false;
        while(n%2==0) n/=2;
        return n==1;
    }
    */
    
    bool isPowerOfTwo(int n) 
    {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};