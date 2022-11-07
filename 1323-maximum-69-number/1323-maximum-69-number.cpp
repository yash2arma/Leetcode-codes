class Solution 
{
public:
    /*
    int maximum69Number (int num) 
    {
        string n = to_string(num);
        
        for(int i=0; i<n.size(); i++)
        {
            if(n[i]=='6')
            {
                n[i]='9';
                break;
            }
        }
        
        return stoi(n);
    }
    */
    
    /*
    int maximum69Number (int num) 
    {
        int maxi=num;
        int temp=0, new_n, p=0, rem, x;
        
        
        while(num)
        {
            rem = num%10;
            num /= 10;
            
            if(rem==6)
            {
                x = pow(10, p)*9 + temp;
                new_n = num*pow(10, p+1) + x;
                maxi = max(maxi, new_n);
            }
            
            temp = (pow(10, p) * rem) + temp;
            p++;
            cout<<temp<<" ";
            
        }
        
        return maxi;
    }
    */
    int maximum69Number (int num) 
    {
        int last_dig=-1, dig_cnt=0, temp=num;
        
        
        while(temp)
        {
            if(temp%10==6)
                last_dig = dig_cnt;
            
            dig_cnt++;
            temp /= 10;
        }
        
        if(last_dig==-1) return num;
        
        return num + pow(10, last_dig)*3;
    }
        
};