class Solution 
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());
        int low=0, high=n-1;
        int p=power;
        int score=0;
        int maxi=0;
        
        while(low<=high)
        {
            if(tokens[low] <= p)
            {
                score++;
                p -= tokens[low++];
                
            }
            
            else if(score>=1)
            {
                p += tokens[high--];
                score--;
            }
            
            else
                break;
            
            maxi = max(maxi, score);
        }
        return maxi;
        
    }
};