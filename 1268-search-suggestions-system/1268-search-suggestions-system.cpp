class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        
        int size=0;
        string cur = "";
        for(auto it: searchWord)
        {
            vector<string> typed;
            cur += it;
            size++;
            int j=0;
            for(auto product:products)
            {
                if(j==3) break;
                
                if(product.substr(0, size) == cur)
                {
                    typed.push_back(product);
                    j++;
                }
                    
            }
            res.push_back(typed);
        }
        return res;
    }
};