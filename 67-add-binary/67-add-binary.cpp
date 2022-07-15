class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i=a.size()-1, j=b.size()-1;
        int x, y;
        int carry=0, sum=0;
        string res="";
        while(i>=0 && j>=0)
        {
            x = a[i]-'0';
            y = b[j]-'0';
            sum = x+y+carry;
            res = to_string(sum%2) + res;
            carry = sum/2;
            i--;
            j--;
        }
        
        while(i>=0)
        {
            x = a[i]-'0';
            sum = x+carry;
            res = to_string(sum%2) + res;
            carry = sum/2;
            i--;
        }
        
        while(j>=0)
        {
            y = b[j]-'0';
            sum = y+carry;
            res = to_string(sum%2) + res;
            carry = sum/2;
            j--;
        }
        
        if(carry==1)
            res = "1" + res;
            
        return res;
    }
};