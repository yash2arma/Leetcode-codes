/*
"Flush": Five cards of the same suit.
"Three of a Kind": Three cards of the same rank.
"Pair": Two cards of the same rank.
"High Card": Any single card.
*/

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) 
    {
        map<int,int> same_suit;
        map<int,int> same_rank;
        for(int i=0; i<ranks.size(); i++)
        {
            same_suit[suits[i]-'a']++;
            same_rank[ranks[i]]++;
        }
        
        for(int i=0; i<ranks.size(); i++)
        {
            if(same_suit[suits[i] - 'a'] > 4)
                return "Flush";
            
            else if(same_rank[ranks[i]] > 2)
                return "Three of a Kind";
            
            else if(same_rank[ranks[i]] > 1)
                return "Pair";
        }
        
        return "High Card";
        
    }
};