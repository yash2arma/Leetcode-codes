class Solution 
{
public:
//     vector<int> findArray(vector<int>& pref) 
//     {
//         int n = pref.size();
//         vector<int> ans(n);
//         int prex=0;
//         ans[0]=pref[0];
        
//         for(int i=1; i<n; i++)
//         {
//             prex ^= ans[i-1];
//             ans[i] = prex^pref[i];
//         }
//         return ans;
//     }
// };

vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        
        vector<int> arr(n);
        arr[0] = pref[0];
        
        for( int i=1 ; i<pref.size() ; i++ ){
            
            arr[i] = pref[i-1]^pref[i] ;
        }
        return arr;
    }
};