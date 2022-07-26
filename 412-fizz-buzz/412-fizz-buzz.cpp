class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> ans;
        int div3, div5;
        for(int i=1; i<=n; i++)
        {
            div3 = i%3;
            div5 = i%5;
            
            if(div3==0 && div5==0)
                ans.push_back("FizzBuzz");
            
            else if(div3==0)
                ans.push_back("Fizz");
            
            else if(div5==0)
                ans.push_back("Buzz");
            
            else
                ans.push_back(to_string(i));
            
        }
        return ans;
    }
};