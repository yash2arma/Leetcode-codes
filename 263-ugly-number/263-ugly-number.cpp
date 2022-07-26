class Solution {
public:
    /*bool isUgly(int n) 
    {
        if(n<=0) return false;
        while(n!=1)
        {
            if(n%2==0)
                n /= 2;
            else if(n%3==0)
                n /= 3;
            else if(n%5==0)
                n /= 5;
            else
                return false;
        }
        return true;
    }
    */
    bool isUgly(int num) 
    {
        if(num <= 0) return false;

        while(num%2 == 0) num/=2;
        while(num%3 == 0) num/=3;
        while(num%5 == 0) num/=5;

        return num == 1;
    }
};