class Solution 
{
public:
    int garbageCollection(vector<string>& gar, vector<int>& tra) 
    {
        int g_cnt=0, p_cnt=0, m_cnt=0;
        int last_g=0, last_p=0, last_m=0;
            
        for(int i=0; i<gar.size(); i++)
        {
            for(auto it:gar[i])
            {
                if(it=='M')
                {
                    m_cnt++;
                    last_m=i;
                }
                if(it=='P')
                {
                    p_cnt++;
                    last_p=i;
                }
                if(it=='G') 
                {
                    g_cnt++;
                    last_g=i;
                }
            }
        }
        
        int tot=m_cnt+p_cnt+g_cnt;
        int sum=0;
        for(int i=0; i<tra.size(); i++)
        {
            sum += tra[i];
            if(last_g>0 && last_g==i+1)
                tot += sum;
            if(last_p>0 && last_p==i+1)
                tot += sum;
            if(last_m>0 && last_m==i+1)
                tot += sum;   
        }
        return tot;
        
        
    }
};