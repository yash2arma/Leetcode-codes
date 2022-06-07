class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        if(n==0) return;
        if(m==0) 
        {
            nums1 = nums2;
            return;
        }
        
        int p1=0, p2=0, size=m;
        while(p1<m && p2<n)
        {
            if(nums1[p1]<=nums2[p2])
                p1++;
            
            else
            {
                while(size>p1)
                {
                    nums1[size] = nums1[size-1];
                    size--;
                }
                m++;
                size = m;
                nums1[p1] = nums2[p2];
                p1++;
                p2++;
            }
        }
        
        while(p2<n)
        {
            nums1[p1] = nums2[p2];
            p1++; p2++;
        }

    }
};