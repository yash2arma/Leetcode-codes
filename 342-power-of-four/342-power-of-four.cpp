class Solution {
public:
    /*bool isPowerOfFour(int n) 
    {
        if(n==0) return false;
        while(n%4==0)
        {
            n /= 4;
        }
        return n==1;
        
    }
    */
    bool isPowerOfFour(int num) 
    {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
    }
};