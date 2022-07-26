class Solution {
public:
    int bitwiseComplement(int num) 
    {
        if(num==0) return 1;
        if(num==1) return 0;
        long long n=1;
        while(n<=num)
            n = n*2;
        
        n -= 1;
        
        return n^num; 
    }
};