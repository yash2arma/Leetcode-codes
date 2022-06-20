/*
class Solution {
public:
    
    //function for comparing and getting large size string in sorting
    static bool larger(string s1, string s2)
    {
        return s1.length() > s2.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) 
    {
        unordered_map<string, int> mp; //store word and its occurence
        int ans = 0;
        
        sort(words.begin(), words.end(), larger); //sort words in decreasing order of their length
        
        for(auto word:words) //enter each word in the hashmap
            mp[word]++;
        
        int wordsize;
        string s;
        //for each word found in hashmap, add its length+1 to ans, add +1 for # included
        for(auto word:words) 
        {
            wordsize = word.size();
            if(mp[word]>0)
                ans += wordsize+1;
            
            //Remove all suffixes of the word from hashmap if exist as they are already covered
            
            for(int j=wordsize-1; j>=0; j--)
            {
                s = word.substr(j, wordsize-j);
                mp[s] = 0;
            }
        }
        
        return ans;
    }
};
*/

//Reverse String Approach:
/*class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        for(auto &word: words) //reverse each word in words i.e. time->emit
            reverse(word.begin(), word.end());
        
        sort(words.begin(), words.end()); //sort words in increasing order of their length
        
        int n = words.size();
        string str = words[0]; 
        int ans=0, wordsize;
        
        //compare adjacent words if both are different we add wordsize+1 in ans, +1 for #
        for(int i=1;i<n;i++) 
        {
            wordsize = str.size();
            cout<<words[i]<<" ";
            if(words[i].compare(0, wordsize, str)) //if both words are same return 0 else 1 
                ans += 1+wordsize;
            cout<<ans<<endl;
    
            str = words[i];
        }
        ans += str.size()+1; //to handle last word and condition when size of words is 1
        return ans;
    }
};
*/

class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        set<string> s(words.begin(), words.end());
        
        for(auto &word: words)
        {
            cout<<word<<" ";
            for(int i=1; i<word.size(); i++)
            {
                s.erase(word.substr(i));
            }
        }
        
        int ans=0;
        
        for(auto word:s)
            ans += word.size()+1;
        
        return ans;
    }
};