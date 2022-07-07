class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string min=*min_element(strs.begin(),strs.end());  //smallest string
        string mx=*max_element(strs.begin(),strs.end()); //largest one
        
        int i=0;
        int j=0;
        
        while(i<min.size() and min[i]==mx[j]) {   //loop until characters are matching
            i++;
            j++;
        }
        return mx.substr(0,i);
        
    }
};