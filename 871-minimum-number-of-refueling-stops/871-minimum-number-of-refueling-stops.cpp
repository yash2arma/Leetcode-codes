/*
class Solution 
{
public:
    
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>> s) 
    {
        long dp[501] = {startFuel};
        for (int i = 0; i < s.size(); ++i)
            for (int t = i; t >= 0 && dp[t] >= s[i][0]; --t)
                dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1]);
        
        for (int t = 0; t <= s.size(); ++t)
            if (dp[t] >= target) return t;
        
        return -1;
    }
};
*/

//Approach-3 : O(nlog(n)) using max-heap
//Similar Problem : Leetcode 1642. Furthest Building You Can Reach
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        priority_queue<int> pq; //max heap
        /*
			if we can't reach target, I will first use the largestfuel Station
			(which can take me farthest) and move ahead and keep doing this.
        */
        int curr = startFuel; //my current position
        int i = 0; //station index
        int result = 0;
        while(curr < target) { //until I reach my target
            while(i < n && curr >= stations[i][0]) {
                /*
					  Sice, I am already ahead of or at this station
					  (i.e. curr >= stations[i][0])  we don't use this
					  station and try to move ahead but I store this
					  station in maxheap to use in future
				*/
                pq.push(stations[i][1]);
				//Keep the station at top which can take me farthest (maximum gas)
                i++;
            }
            
            if(pq.empty()) //we can't move further now
                return -1;
            
            int dist = pq.top();
            pq.pop();
            
            curr += dist;
            result++;
        }
        
        return result;
        
    }
};