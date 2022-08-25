class Solution 
{
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
        for(int i=left; i<=right; i++)
        {
            bool f=0;
            for(auto it:ranges)
            {
                if(it[0] <= i && i <= it[1])
                {
                    f=1;
                    break;
                }
            }
            if(!f) return 0;
        }
        return 1;
    }
};