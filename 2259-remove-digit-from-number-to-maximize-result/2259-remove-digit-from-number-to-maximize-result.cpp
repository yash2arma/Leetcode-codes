class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        string ans = "0";
        
        //Iterating over the number and whenever digit is found, we remove it and
        //string that has been made after removing digit will be compared to get max string 
        for(int i=0; i<number.size(); i++)
        {
            if(number[i]==digit)
            {
                string temp = number.substr(0,i) + number.substr(i+1, number.size());
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};