class NumberContainers {
public:
    map<int, int> idx_num;
    map<int, set<int>> num_idx;
    
    NumberContainers() 
    {
        
    }
    
    void change(int index, int number) 
    {
        auto it = idx_num.find(index);
        if(it != idx_num.end())
            num_idx[it->second].erase(index);
        
        idx_num[index] = number;
        num_idx[number].insert(index);       
    }
    
    int find(int number) 
    {
        auto it = num_idx.find(number);
        
        return (it==num_idx.end() || it->second.empty()) ? -1 : *it->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

/*
class NumberContainers {
public:
    unordered_map<int, int> ind_num;
    unordered_map<int, set<int>> num_inds;
    void change(int index, int number) {
        auto it = ind_num.find(index);
        if (it != end(ind_num))
            num_inds[it->second].erase(index);
        ind_num[index] = number;
        num_inds[number].insert(index);
    }
    int find(int number) {
        auto it = num_inds.find(number);
        return it == end(num_inds) || it->second.empty() ? -1 : *begin(it->second);
    }
};
*/