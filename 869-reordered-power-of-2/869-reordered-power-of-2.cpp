class Solution 
{
public:
    bool reorderedPowerOf2(int n) 
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        vector<string> power(31);
        int num;
        for(int i=0; i<=30; i++)
        {
            num = pow(2,i);
            power[i] = to_string(num);
        }
        
        for(int i=0; i<=30; i++)
        {
            sort(power[i].begin(), power[i].end());
        }
        
        for(int i=0; i<=30; i++)
        {
            if(power[i]==s) return true;
        }
        return false;
    }
    
};