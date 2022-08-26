class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int count=0;
        int n=shifts.size();

        //eg1- [3,5,9] -> [17,14,9]
        for(int i=n-1; i>=0; i--)
        {
            count = (count+shifts[i])%26;
            shifts[i] = count;
        }
        
        char c;
        for(int i=0; i<n; i++)
        {
            c = 'a' + (26 + (s[i]-'a') + shifts[i])%26;
            s[i] = c;
        }
        return s;
        
    }
};