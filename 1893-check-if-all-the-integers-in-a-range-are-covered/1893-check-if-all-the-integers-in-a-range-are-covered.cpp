class Solution 
{
public:
    /*bool isCovered(vector<vector<int>>& ranges, int left, int right) 
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
    */
    
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
        vector<int> line(52, 0);
        for(auto &r: ranges)
            line[r[0]]++, line[r[1]+1]--;
        
        for(int i=1, overlap=0; i<=right; i++)
        {
            overlap+=line[i];
            if(i>=left && overlap==0)
                return 0;
        }
        return 1;
    }
};