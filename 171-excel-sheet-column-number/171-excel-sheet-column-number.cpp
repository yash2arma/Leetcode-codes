class Solution 
{
public:
    int titleToNumber(string column) 
    {
        long long num = 0;
        long long cnt = 1;
        for(int i=column.size()-1; i>=0; i--)
        { 
            num += (column[i]-'A'+1)*cnt;
            cnt *= 26;
        }
        return num;        
    }
};