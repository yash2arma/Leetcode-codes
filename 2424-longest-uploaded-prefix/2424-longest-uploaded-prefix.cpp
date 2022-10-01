class LUPrefix {
public:
    
    vector<int> pre;
    int val=0;
    LUPrefix(int n) 
    {
        pre.resize(n+2, 0);
    }
    
    void upload(int video) 
    {
        pre[video] = 1;
        
    }
    
    int longest() 
    {
        while(pre[val+1]==1)
                val++;
        
        return val;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */