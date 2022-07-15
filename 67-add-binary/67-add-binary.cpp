class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i=a.size()-1, j=b.size()-1;
        int x, y;
        int carry=0, sum=0;
        string res="";
        while(i>=0 || j>=0 || carry)
        {
            sum = carry;
            if(i>=0)
            {
                sum += a[i]-'0';
                i--;
            }
            if(j>=0)
            {
                sum += b[j]-'0';
                j--;
            }

            res = to_string(sum%2) + res;
            carry = sum/2;
        }
            
        return res;
    }
};