// Approach: Calculate frequency of each char then just decrese frequency of each char by 1 and check whether we get equal frequency or not

/*class Solution 
{
public:
    bool equalFrequency(string word) 
    {
        vector<int> mp(26, -1); //initially marked with -1 to show no char
        
        for(auto it:word)
        {
            if(mp[it-'a']==-1) mp[it-'a']=1;
            else mp[it-'a']++;
        }
            
        
        for(int i=0; i<26; i++)
        {
            if(mp[i]==-1) continue; 
            
            mp[i]--;
            if(mp[i]==0) mp[i]=-1;
            
            int fl=0, cnt=0, fl2=0;
            for(int i=0; i<26; i++)
            {
                if(mp[i]==-1) continue;
                
                if(fl==0)
                {
                    cnt = mp[i];
                    fl=1;
                }
                
                if(mp[i]!=cnt)
                {
                    fl2=1;
                    break;
                }
            }
            if(fl2==0) return true;
            
            if(mp[i]==-1) mp[i]=1;
            else mp[i]++;
            
        }
        return false;
    }
};
*/

class Solution 
{
public:
    bool equalFrequency(string word) 
    {
        vector<int> mp(26, 0); 
        
        for(auto it:word) //storing frequency
        {
            mp[it-'a']++;
        }
            
        
        for(int i=0; i<26; i++) 
        {
            if(mp[i]==0) continue;  //if no char available then check for next char
            
			//if char present then decrease its frequency by 1
            mp[i]--;
            
            int fl=0, cnt=0, fl2=0; //fl for storing frequency 1st time, fl2 assures whether we get equal frequency or not
            for(int i=0; i<26; i++) //check whether frequency is equal for other char
            {
                if(mp[i]==0) continue;
                
                if(fl==0)  //storing fre 1st time in cnt
                {
                    cnt = mp[i];
                    fl=1;
                }
                
                if(mp[i]!=cnt) 
                {
                    fl2=1;
                    break;
                }
            }
            if(fl2==0) return true; 
            
            mp[i]++; //again restoring frequency of char in mp 
            
            
        }
        return false;
    }
};