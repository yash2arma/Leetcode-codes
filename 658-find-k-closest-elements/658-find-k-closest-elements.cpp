class Solution 
{
public:
    /*
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto it:arr)
            pq.push({abs(it-x), it});
        
        vector<int> res;
        for(int i=0; i<k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    */
    
    vector<int> findClosestElements(vector<int>& A, int k, int x) 
    {
        int left=0, right=A.size()-k;
        
        while (left < right) 
        {
            int mid = (left+right)/2;
            
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};