//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    int editDistance(string s, string t) {
        int m=s.size(), n=t.size();
        vector<int> pre(n+1, 0), cur(n+1, 0);
        
        for(int j=0; j<=n; j++) pre[j] = j;
        
        for(int i=1; i<=m; i++)
        {
            cur[0] = i;
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==t[j-1]) cur[j] = pre[j-1];
                else
                {
                    cur[j] = 1 + min({cur[j-1], pre[j], pre[j-1]});
                }
            }
            pre = cur;
        }
        return pre[n];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends