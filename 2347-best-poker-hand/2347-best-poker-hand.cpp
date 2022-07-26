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
            same_suit[suits[i]-'a']++; //storing count of same char
            same_rank[ranks[i]]++; //storing count of same rank
        }
        
        int flush=0, three=0, pair=0;
        for(int i=0; i<ranks.size(); i++)
        {
			//apply operations as per the condition given 
            if(same_suit[suits[i] - 'a'] > 4) 
                flush=1;
            
            else if(same_rank[ranks[i]] > 2)
                three=1;
            
            else if(same_rank[ranks[i]] > 1)
                pair=1;
        }
        
        if(flush) return "Flush";
        else if(three) return "Three of a Kind";
        else if(pair) return "Pair";
        return "High Card";
        
    }
};