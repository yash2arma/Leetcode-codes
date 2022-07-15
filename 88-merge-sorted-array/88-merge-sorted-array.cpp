/*class Solution {
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
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int e=nums1.size()-1;
        int s1=m-1, s2=n-1;
        while(s1>=0 || s2>=0)
        {
            if(s1>=0 && s2>=0)
            {
                if(nums1[s1] > nums2[s2])
                    nums1[e--] = nums1[s1--];
                else
                    nums1[e--] = nums2[s2--];
            }
            
            else if(s1>=0)
                nums1[e--] = nums1[s1--];
            
            else
                nums1[e--] = nums2[s2--];
        }

    }
};