class Solution 
{
public:
    /*
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string a, b;
        
        for(auto it:word1)
            a += it;
        
        for(auto it:word2)
            b += it;
        
        return a==b;
        
    }
    */
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        int w1i=0, w2i=0, c1i=0, c2i=0;
        
        while(true)
        {
            if(word1[w1i][c1i] != word2[w2i][c2i]) return false;
            
            c1i++, c2i++;
            
            //when we reach at the end char of a word
            if(c1i==word1[w1i].size()) 
            {
                w1i++;
                c1i=0;
            }
            
            if(c2i==word2[w2i].size())
            {
                w2i++; 
                c2i=0;
            }
            
            if(w1i == word1.size() && w2i==word2.size()) break;
            
            if(w1i == word1.size() || w2i==word2.size()) return false;
            
        }
        return true;
    }
};