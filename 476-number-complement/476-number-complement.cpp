class Solution {
public:
    int findComplement(int num) 
    {
        if(num==1) return 0;
        long long n=1;
        while(n<=num)
            n = n*2;
        
        n -= 1;
        
        return n^num; 
    }
};