class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long res(0);
        int n(size(nums));
        
        for (int i=0; i<n; i++) {
            nums[i] = i - nums[i];
        }
        
        unordered_map<int, int> m;
        for (int i=0; i<n; i++) {
            res += (m.count(nums[i])) ? i - m[nums[i]] : i;
            m[nums[i]]++;
        }
        return res;
    }
};