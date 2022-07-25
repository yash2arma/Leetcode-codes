class Solution {
public:
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
};