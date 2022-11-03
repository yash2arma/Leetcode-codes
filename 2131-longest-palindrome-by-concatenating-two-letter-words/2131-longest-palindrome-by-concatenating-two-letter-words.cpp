class Solution 
{
public:
    
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> mp;
        int n=words.size();
        string rev;
        int count=0;
        
        for(int i=0; i<n; i++)
        {
            rev =words[i];
            reverse(rev.begin(), rev.end());
            
            if(mp[rev] > 0) 
            {
                count += 4;
                mp[rev]--;
            }
            
            else mp[words[i]]++;
                
        }
        
        for(auto it:mp)
        {
            if(it.first[0]==it.first[1] && it.second>0)
                return count+2;
        }
        
        return count;
                
    }
};