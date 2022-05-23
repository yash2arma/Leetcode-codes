class Solution {
public:
    //store the occurence of card in the vector when it comes 2nd time, 
    //we calculate the length from its first occurence and then find mini length 
    
    int minimumCardPickup(vector<int>& cards) 
    {
        vector<int> occur(1e6+1, -1);
        int mini = INT_MAX;
        for(int i=0; i<cards.size(); i++)
        {
            if(occur[cards[i]] != -1)
            {   //element occuring more than one time
                mini  = min(mini, i- occur[cards[i]]+1);
            }
           
           occur[cards[i]] = i;
       }
        
        return mini==INT_MAX ? -1 : mini;
    }
};