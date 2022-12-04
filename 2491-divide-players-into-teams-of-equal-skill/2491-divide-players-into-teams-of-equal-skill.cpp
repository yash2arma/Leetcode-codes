class Solution 
{
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n=skill.size();
        sort(skill.begin(), skill.end());
        
        int l=0, h=n-1;
        long long chem=0;
        int team1 = skill[l]+skill[h];
        chem += skill[l++]*skill[h--];
        
        while(l<h)
        {
            if(team1 != skill[l]+skill[h]) return -1;
            chem += skill[l]*skill[h];
            l++, h--;
        }
        
        return chem;
    }
};