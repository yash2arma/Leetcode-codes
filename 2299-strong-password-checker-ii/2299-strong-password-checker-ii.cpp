class Solution {
public:
    bool strongPasswordCheckerII(string pwd) 
    {
        int lower=0, upper=0, digit=0, special=0;
        
        for(int i=0; i<pwd.length(); i++)
        {
            if(i>0 && pwd[i]==pwd[i-1])  return false;
            
            if(islower(pwd[i])) lower=1;
            
            else if(isupper(pwd[i])) upper=1;
            
            else if(isdigit(pwd[i])) digit=1;
            
            else special=1;
        }
        
        return (pwd.length()>7 && lower && upper && digit && special);
        
    }
};