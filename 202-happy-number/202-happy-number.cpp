class Solution {
public:
    /*bool isHappy(int n) 
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
    */
    
    int digitSquareSum(int n) 
    {
        int sum = 0, tmp;
        while (n) 
        
        {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        int slow, fast;
        slow = fast = n;
        do 
        {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        } 
        while(slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }
};