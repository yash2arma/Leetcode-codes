class Solution 
{
public:
    int countTime(string time) 
    {   
        int ans=1;
        
        if(time[0]=='?' && time[1]=='?') //for HH
                ans *= 24;   
        
        if(time[0]=='?' && time[1]!='?') 
        {
            if(time[1] < '4') 
                ans *= 3;
            else
                ans *= 2;
        }

        if(time[1]=='?' && time[0]!='?')
        {
            if(time[0] < '2')
                ans *= 10;
            else
                ans *= 4;
        }
        
        if(time[3]=='?')
        {
            ans *= 6;
        }

        if(time[4]=='?')
        {
            ans *= 10;
        }       
            
        return ans;
    }
};