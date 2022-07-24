class Solution 
{
public:
    /*int equalPairs(vector<vector<int>>& grid) 
    {
        int count=0;
        int n=grid.size();
         
        for(int i=0; i<n; i++) //for row
        {
            for(int j=0; j<n; j++) //for column
            {
                for(int k=0; k<n; k++) //for comparing each row with every column
                {
                    if(grid[i][k] != grid[k][j]) break;
                    if(k==n-1) count++; //if row is totally equal to the column we increase the count
   
               }
            } 
            
        }
        return count;
    }
    */
    
    int equalPairs(vector<vector<int>>& grid) 
    {
        int count=0;
        map<vector<int> , int> mp;
        int n=grid.size();
        
        
         
        for(auto it:grid) //storing rows
            mp[it]++;
            
        
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            for(int j=0; j<n; j++) 
            {
                temp.push_back(grid[j][i]); //storing column
                
                if(mp[temp]) count += mp[temp]; //if row is totally equal to the column we increase the count

           }
        } 
           
        return count;
    }
};