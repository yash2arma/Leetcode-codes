class Solution 
{
public:
    int numberOfSteps(int num) 
    {
        int count=0;
        while(num)
        {
            if(num%2) num -= 1; //when num is odd, substract 1
               
            else num /= 2; //when num is even, divde by 2
                    
            count++;
        }
        return count;
    }
};