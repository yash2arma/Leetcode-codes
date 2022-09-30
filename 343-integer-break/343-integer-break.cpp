class Solution 
{
public:
    
    int integerBreak(int n) 
    {
        if(n<=2) return 1;
        
        vector<int> maxpro(n+1, 0);
        maxpro[2] = 1;
        
        for(int i=3; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                maxpro[i] = max(maxpro[i], max(j*(i-j), j*maxpro[i-j]));
            }
        }
        return maxpro[n];
    }
};