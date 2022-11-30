class RandomizedSet 
{
public:
    set<int> s; 
    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        if(s.count(val)) return false; //when value exist
        s.insert(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if(!s.count(val)) return false; //when value doesn't exist
        s.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        //take any random number and do modules with size of nums 
        //to get number lies in nums index range and return it
        return *next(s.begin(), rand()%s.size());
    }
};
