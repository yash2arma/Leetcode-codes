class Solution 
{
public:
    
    long long digsum(long long  n)
    {
        long long sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) 
    {
        if(digsum(n)<=target)return 0;
        long long count=10;
        long long temp=n;
        
        while(digsum(temp)> target)
        {
            long long mod=n%count;
            temp=n+count-mod;
            cout<<temp<<" ";
            count*=10;
        }
        return temp-n;
    }
};