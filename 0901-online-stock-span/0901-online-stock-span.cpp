class StockSpanner {
public:
    
    vector<int> stock;
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
        stock.push_back(price);
        int maxi=0;
        int n=stock.size();
        int curr = stock[n-1];
        int i;
        for(i=n-2; i>=0; i--)
        {
            
            if(stock[i] > curr)
                break;
        }
        return n-1-i;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */