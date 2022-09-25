class MyCircularQueue 
{
public:
    vector<int> q;
    int front=0, rear=0, count=0;
    
    
    MyCircularQueue(int k) 
    {
        q.resize(k);
    }
    
    bool enQueue(int value) 
    {
        if(count==q.size()) return false;
    
        q[rear%q.size()]=value;
        rear++; count++;
        return true;
    }
    
    bool deQueue() 
    {
        if(count==0) return false;
        
        q[front%q.size()] = -1;
        front++; count--;
        return true;
    }
    
    int Front() 
    {
        if(count==0) return -1;
        return q[front%q.size()];
    }
    
    int Rear() 
    {
        if(count==0) return -1;
        return q[(rear-1)%q.size()];
    }
    
    bool isEmpty() 
    {
        if(count==0) return true;
        return false;
    }
    
    bool isFull() 
    {
        if(count==q.size()) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */