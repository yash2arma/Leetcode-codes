// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int left=0, right=n;
        int mid;
        while((right-left)>1)
        {
            mid = left+(right-left)/2;
            
            if(isBadVersion(mid))
                right=mid;
            
            else left = mid;
        }
        return right;
    }
};
