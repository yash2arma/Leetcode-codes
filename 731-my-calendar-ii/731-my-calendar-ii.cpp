class MyCalendarTwo 
{
public:
    map<int, int> events;
    MyCalendarTwo() 
    {
        
    }
    
    bool book(int s, int e) 
    {
        events[s]++;
        events[e]--;
        int booked = 0;
        
        for(auto it:events)
        {
            booked += it.second;
            if(booked == 3)
            {
                events[s]--;
                events[e]++;
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */