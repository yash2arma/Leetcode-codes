class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        //Given string contains letters, digits, symbols and spaces 
        //create vector map of size 128 because in ascii table we have total 128 characters
        vector<int> map(128, -1); 
        
        int left=0, right=0, len=0; //define left, right pointers and len to calculate length
        
        //iterate till right pointer is less than string size    
        while(right<s.length())
        {
            //to avoid repeating characters we move left pointer next to the repeated char
            if(map[s[right]] != -1) left = max(left, map[s[right]]+1);
            
            map[s[right]] = right; //change the index of repeated char
            
            len = max(len, right-left+1);   //calculate length
            
            right++; //move right pointer by 1
        }
        
        return len;
        
    }
};


/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        //map store char and its index
        unordered_map<char, int> mp;
        int f=0, e=0;
        int n=s.length(), maxi=0;
        
        while(e<n)
        {
            //when char is repeating or already present in the map
            if(mp.find(s[e]) != mp.end())
            {
                while(f<mp[s[e]]) mp.erase(s[f++]); //we erase all the char till most recent repeating char
                f = mp[s[e]]+1; //move f pointer next to the repeated char
            }
            mp[s[e]] = e; //store the index of the char in the map
            maxi = max(maxi, e-f+1); //calculate length
            e++; //move e pointer by 1
        }
        return maxi;
        
    }
};
*/