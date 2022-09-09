class Solution 
{
public:
    
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) 
    {
        int mini = INT_MIN;
        int ans=0;
        sort(p.begin(), p.end(), compare);
        
        for(int i=p.size()-1; i>=0; i--)
        {
            if(p[i][1] < mini)
                ans++;
            else
                mini = max(mini, p[i][1]);
        }
        return ans;
    }
};