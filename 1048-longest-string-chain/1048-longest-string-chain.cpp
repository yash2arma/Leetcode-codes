/*words = ["a","b","ba","bca","bda","bdca"]

1) word = "a", prev = "", dp = {"a": 1}; It means that ending with "a", the max size of chain is 1.
2) word = "b", prev = "", dp = {"a": 1, "b": 1}; It means that ending with "b", the max size of chain is 1.
3) word = "ba", prev = "a" or "b", dp = {"a": 1, "b": 1, "ba": 2}; It means that ending with "ba", the max size of chain is 2.
	Here, both "a" and "b" can be the predecessor. We are interested only in length not the actual chain!
4) word = "bca", prev = "ba", dp = {"a": 1, "b": 1, "ba": 2, "bca":3}; It means that ending with "bca", the max size of chain is 3.
5) word = "bda", prev = "ba", dp = {"a": 1, "b": 1, "ba": 2, "bca":3, "bda": 3}; It means that ending with "bda", the max size of chain is 3.
6) word = "bdca", prev = "bda" or "bca", dp = {"a": 1, "b": 1, "ba": 2, "bca":3, "bda": 3, "bdca": 4}; It means that ending with "bdca", the max size of chain is 4.
*/

class Solution {
public:
    
    static bool compare(string s1, string s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string, int> dp; //define hashmap dp which stores predecessor word and chain size for it
        
        //sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1.length()<s2.length();});
        sort(words.begin(), words.end(), compare);
        
        int len = 1; //store longest possible word chain
        
        for(auto word:words) //cover each word in the vector words 
        {
            dp[word]=1; //A single word has word chain 1
            for(int i=0; i<word.length(); i++) //cover all the alphabets in the word
            {
                //removing ith alphabet from the string and check remaining string is available in the dp 
                string pred = word.substr(0,i) + word.substr(i+1); 
                
                if(dp.find(pred) != dp.end()) //if it presents
                {
                    dp[word] = dp[pred]+1; //then increase word chain by 1 and store in dp
                    len = max(len, dp[word]); //find max length
                }
            }
        }
        return len;
        
        
    }
};