class Solution {
public:
    /*bool isOneBitCharacter(vector<int>& bits) 
    {
        if(bits.size()==1) return true;
        for(int i=0; i<bits.size(); i++)
        {
            if(bits[i]==1)
            {
                if(i+1 >= bits.size()-1)
                    return false;
                i++;
            }
        }
        return true;
        
    }*/
    
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int count_1 = 0;
        for (int i = bits.size()-2; i>=0 && bits[i]==1; i--) count_1++;
        return (count_1 % 2 == 0);
    }
    
    
};