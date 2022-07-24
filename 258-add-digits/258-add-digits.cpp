class Solution {
public:
    int addDigits(int num) 
    {
        int sum;
        while(num>9)
        {
            sum = 0;
            while(num)
            {
                sum += num%10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
    
};