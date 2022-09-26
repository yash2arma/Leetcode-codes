class Solution 
{
    int uf[26];
    int find(int x)
    {
        return uf[x]==x? x : (uf[x] = find(uf[x]));
    }
    public:
        bool equationsPossible(vector<string>& equa)
        {
            for(int i=0; i<26; i++) uf[i]=i;
            
            for(auto it:equa)
            {
                if(it[1]=='=') uf[find(it[0]-'a')] = find(it[3]-'a');
            }
            
            for(auto it:equa)
            {
                if(it[1]=='!' && find(it[0]-'a') == find(it[3]-'a')) return false;
            }
            return true;
        }
};