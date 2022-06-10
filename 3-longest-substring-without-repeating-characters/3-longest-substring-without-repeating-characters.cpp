class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> map(128, -1);
        int left=0, right=0, len=0;
        
        while(right<s.length())
        {
            if(map[s[right]] != -1) left = max(left, map[s[right]]+1);
            map[s[right]] = right;
            len = max(len, right-left+1);
            right++;
        }
        return len;
        
    }
};