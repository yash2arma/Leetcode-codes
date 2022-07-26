class Solution {
public:
    bool isHappy(int n) 
    {
        int count=20;
        int sum;
        while(count--)
        {
            sum = 0;
            while(n)
            {
                int temp = n%10;
                sum += temp*temp;
                n /= 10;
            }
            n = sum;
            if(n==1) return true; 
        }
        return false;
        
    }
};