class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts)     {
        sort(hcuts.begin(), hcuts.end());
        sort(vcuts.begin(), vcuts.end());
        
        int max_h = max(hcuts[0] - 0, h - hcuts[hcuts.size()-1]);
        int max_w = max(vcuts[0] - 0, w - vcuts[vcuts.size()-1]);
        
        for(int i=1; i<hcuts.size(); i++)
            max_h = max(max_h, hcuts[i]-hcuts[i-1]);
        
        for(int i=1; i<vcuts.size(); i++)
            max_w = max(max_w, vcuts[i]-vcuts[i-1]);

        return (int)((long)max_w*max_h  % 1000000007); 
    }
};