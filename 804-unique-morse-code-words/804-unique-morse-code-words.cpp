class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
                               ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
                               ".--","-..-","-.--","--.."};
        
        set<string> ans;
        string morse;
        for(auto word: words)
        {
            morse="";
            for(auto c:word)
                morse += code[c-'a'];
            
            ans.insert(morse);
        }
        return ans.size();
        
    }
};