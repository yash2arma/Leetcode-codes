class Solution 
{
public:
    int garbageCollection(vector<string>& gar, vector<int>& tra) 
    {
        int cnt=0;
        int last_g=0, last_p=0, last_m=0;
            
        for(int i=0; i<gar.size(); i++)
        {
            for(auto it:gar[i])
            {
                //finding last index of a type of garbage
                if(it=='M') last_m=i;
                else if(it=='P') last_p=i;
                else last_g=i;
                cnt++; //for any type of garbage it take 1 unit time
            }
        }
        
        int tot=cnt;
        int sum=0;
        for(int i=0; i<tra.size(); i++)
        {
            sum += tra[i];
            if(last_g==i+1) tot += sum;
            if(last_p==i+1) tot += sum;
            if(last_m==i+1) tot += sum;   
        }
        return tot;
        
        
    }
};