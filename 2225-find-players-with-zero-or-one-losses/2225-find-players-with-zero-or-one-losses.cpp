class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        //According to the problem, we need to return players who don't loss any match and players who lost exact one match.
        //So, we traverse through the matches and put winners into set and count no. of matches lost by losers using map.
        //Then we find only those player who lost exact one match and if that player is in the winners then we remove that player.
        //At the end, since we use set and map players are already in ascending order so we just return the vector of winners and losers
        
        
        set<int> winners;
        map<int, int> losers;
        
        //put winners and losers into the ds
        for(auto it:matches)
        {
            winners.insert(it[0]);
            losers[it[1]]++;
        }
        
        vector<int> one_lost;
        
        //find losers who lost exact one match and put them into one_lost
        for(auto it:losers)  //we can also use &[x,cnt]
        {
            if(it.second==1)
                one_lost.push_back(it.first);
            
            //if player in the winners, erase it
            winners.erase(it.first);
        }
               

        return {vector<int>(winners.begin(), winners.end()), one_lost};
    }
};