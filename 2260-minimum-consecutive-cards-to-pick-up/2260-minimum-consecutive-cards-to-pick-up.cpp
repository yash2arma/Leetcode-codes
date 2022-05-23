class Solution {
public:
    //store the 1st occurence of the card in the map when it comes 2nd time, 
    //we calculate the length from its 1st occurence and then find minimum length 
    
    int minimumCardPickup(vector<int>& cards) 
    {
        unordered_map<int,int> indices ;
        int ans = INT_MAX ;
        
        for(int i=0; i<cards.size(); i++)
        {
            //when card comes 1st time we store its index in the map
            if(indices.find(cards[i]) == end(indices))
            {
                indices[cards[i]] = i ;
                continue ;
            }
            //find mini distance by calculating (index of 2nd occurence - index of 1st occurence)
            ans = min(ans, i-indices[cards[i]]+1);
            indices[cards[i]] = i ;
        }
        return ans<INT_MAX ? ans : -1;
    }
};