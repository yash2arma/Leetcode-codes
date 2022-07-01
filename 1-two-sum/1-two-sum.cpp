class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int s) 
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++)
        {
            if(mp.find(s - arr[i]) != mp.end())
            {
                 ans.emplace_back(mp[s-arr[i]]);
                 ans.emplace_back(i);
                break;
            }
            mp[arr[i]] = i;
        }
        return ans;
        
        
    }
};