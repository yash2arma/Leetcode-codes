class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        vector<int> v;
        int sum, n;
        int maxi = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            n = nums[i];
            sum = 0;
            while(n)
            {
                sum += n%10;
                n /= 10;
            }
            v.push_back(sum);
        } 
        
        
        vector<pair<int, int>> p;
        
        for(int i=0; i<nums.size(); i++)
            p.push_back(make_pair(v[i], nums[i]));
        
        sort(p.begin(), p.end()); 
        
        for(int i=1; i<p.size(); i++)
            if(p[i].first==p[i-1].first)
                maxi = max(maxi, p[i].second + p[i-1].second);
    
        return maxi;
        
    }
};