class Solution {
public:
    bool isPalindrome(int x) 
    {       
        // Negative numbers cannot be palindrome
        // Also if the last digit of the number is 0
        // the first digit of the number also needs to be 0
        // Only 0 satisfy this condition
        
        if (x<0 || (x!=0 && x%10==0))
            return false;
        
        //initialize the reverse number...
        int ReverseNumber = 0;

        //process to reverse the number...
        while (x > ReverseNumber){
    	    ReverseNumber = ReverseNumber * 10 + x % 10;
    	    x = x/10;
        // if the reverse of half of the number is equal to the other half then it's a palindrome
        // When x > ReverseNumber, we've reached the middle of the number
        }
        // when length is an odd number, we need to get rid of the middle digit
        // since the middle digit doesn't matter in palindrome
        
        return (x == ReverseNumber || x == ReverseNumber/10);
        
    }
};


