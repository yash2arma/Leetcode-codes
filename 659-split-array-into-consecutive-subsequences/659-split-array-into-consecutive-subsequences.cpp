class Solution {
public:
    bool isPossible(vector<int>& A) 
    {
        unordered_map<int, int> left, last;
        
        for(auto it:A)
            left[it]++;
        
        for(auto i:A)
        {
            if(left[i]==0) continue;
            left[i]--;
            
            if(last[i-1]>0)
            {
                last[i]++;
                last[i-1]--;
            }
            
            else if(left[i+1]>0 && left[i+2]>0)
            {
                left[i+1]--;
                left[i+2]--;
                last[i+2]++;
            }
            
            else
                return false;
        }
        return true;
    }
};