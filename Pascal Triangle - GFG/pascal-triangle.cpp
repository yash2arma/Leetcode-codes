// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) 
    {
        vector<vector<ll>> mat(n);
        for(int i=0; i<n; i++)
        {
            mat[i].resize(i+1);
            mat[i][0] = mat[i][i] = 1;
            for(int j=1; j<i; j++)
                mat[i][j] = (mat[i-1][j-1] + mat[i-1][j]) %1000000007;
        }
        return mat[n-1];
        
        // code here
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends