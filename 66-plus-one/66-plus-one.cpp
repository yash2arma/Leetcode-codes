class Solution {
public:
    vector<int> plusOne(vector<int> &v) 
    {
        int n= v.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]==9)
                v[i]=0;
            
            else 
            {
                v[i]++;
                return v;
            }
        }
        
        v[0]=1;
        v.emplace_back(0);
        return v;
    }
};