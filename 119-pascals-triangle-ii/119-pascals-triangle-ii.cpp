class Solution {
public:
    /*vector<int> getRow(int rowIndex) 
    {
        vector<vector<int>> triangle(rowIndex+1);
        
        for(int i=0; i<=rowIndex; i++)
        {
            triangle[i].resize(i+1);
            triangle[i][0] = triangle[i][i] = 1;
            
            for(int j=1; j<i; j++)
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        return triangle[rowIndex];
        
    }
    */
    
    vector<int> getRow(int rowIndex) 
    {
        vector<int> v;
        vector<int> preV;
        int low=0;
        
        for(int i=0; i<=rowIndex; i++)
        {
            v.clear();
            v.push_back(1);
            
            for(int j=1; j<low; j++)
                v.push_back(preV[j-1] + preV[j]);
            
            if(i!=0) v.push_back(1);
            preV = v;
            low++;
        }
        return v;
        
    }
};