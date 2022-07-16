class Solution {
public:
    string convertToTitle(int col) 
    {
        string column = "";
       
        while(col)
        {
            col -= 1;
            column = (char)('A'+col%26) + column; 
            col /= 26;
        }
        
        return column;
        
    }
};