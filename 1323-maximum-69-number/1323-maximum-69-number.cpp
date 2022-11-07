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
                //cout<<new_n<<" ";
                maxi = max(maxi, new_n);
            }
            
            temp = (pow(10, p) * rem) + temp;
            p++;
            cout<<temp<<" ";
            
        }
        
        return maxi;
    }
};