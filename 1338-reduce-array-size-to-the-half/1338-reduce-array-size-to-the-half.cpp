class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int n=arr.size();
        priority_queue<pair<int, int>> pq;
        sort(arr.begin(), arr.end());
        int cnt=1;
        
        for(int i=0; i<n; i++)
        {
            if(i<n-1 && arr[i]==arr[i+1])
                cnt++;
            else 
            {
                pq.push(make_pair(cnt, arr[i]));
                cnt=1;
            }
        }
        
        int ans=0;
        int m = n;
        while(!pq.empty())
        {
            cnt = pq.top().first;
            pq.pop();
            m -= cnt;
            ans++;
            if(m <= n/2)
                break;
        }
        return ans;
    }
};