//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s)
    {
            int n=s.size(), m=p.size();
        vector<bool> pre(n+1, false), cur(n+1, false);
    
        pre[0]=true;
    
        for(int j=1; j<=n; j++)
            pre[j] = false;
    
    
        for(int i=1; i<=m; i++)
        {
            //Since in tabulation, we update 1st column of each row
            //here, we update 0th index of cur
            int flag = true;
            for(int ii=1; ii<=i; ii++)
            {
                if(p[ii-1] != '*') 
                {
                    flag = false;
                    break;
                }
            }
            cur[0] = flag;
    
            for(int j=1; j<=n; j++)
            {
    
                if(p[i-1]==s[j-1] || p[i-1]=='?')
                    cur[j] = pre[j-1];
    
                else if(p[i-1]=='*')
                    cur[j] = pre[j] | cur[j-1];
                else
                    cur[j] = false;
    
            }
            pre = cur;
    
        }
        return pre[n];
        }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends