class Solution {
public:
    int minimumNumbers(int num, int k) 
    {
        if(num==0) return 0;
        if(k==0) 
        {
            return num%10 == 0 ? 1 : -1;
        }
        
        for(int i=1; i*k<=num; i++)
        {
            if((num - i*k)%10 == 0) return i;
        }
        return -1;
        
    }
};