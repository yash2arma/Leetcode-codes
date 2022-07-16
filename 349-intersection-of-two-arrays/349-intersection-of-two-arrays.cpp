class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        
        int i=0, j=0;
        int m=nums1.size(), n=nums2.size();
        
        while(i<m and j<n)
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                while(i+1<m && nums1[i]==nums1[i+1]) i++;
                while(j+1<n && nums2[j]==nums2[j+1]) j++;
                i++;
                j++;
            }
            
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return ans;
        
    }
};