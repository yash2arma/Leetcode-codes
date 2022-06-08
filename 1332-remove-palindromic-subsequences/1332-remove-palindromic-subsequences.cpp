class Solution {
public:
    int removePalindromeSub(string s) 
    {
        int front=0, end=s.size()-1;
      
        while(s[front]==s[end])
        {
            cout<<s[front]<<" "<<s[end]<<endl;
            front++;
            end--;
            if(front>end) return 1;
        }
        
        return 2;
        
    }
};