class Solution 
{
public:
    int edgeScore(vector<int>& edges) 
    {
        int n=edges.size();
        
        vector<unsigned int> indeg(n, 0);
        
        for(int i=0; i<n; i++) indeg[edges[i]] += i;
        
        return max_element(indeg.begin(), indeg.end()) - indeg.begin();
 
        
        /*unsigned int maxi=0;
        int val=0;
        for(int i=n-1; i>=0; i--)
        {
            if(indeg[i] >= maxi)
            {
                maxi = indeg[i];
                val = i;
            }
        }
        return val;*/
        
        
        
    }
};