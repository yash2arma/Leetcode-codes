class Solution 
{
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> left;
        
        for(auto it:hand) left[it]++;
        
        for(auto it:hand)
        {
            if(left[it]==0) continue;
            left[it]--;
            
            for(int i=1; i<groupSize; i++)
            {
                if(left[it+i]>0) left[it+i]--;
                else return false;
            }
        }
        return true;
        
    }
};