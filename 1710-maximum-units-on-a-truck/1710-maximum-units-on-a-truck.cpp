class Solution {
public:
    static bool compare(vector<int> &box1, vector<int> &box2)
    {
        return box1[1]>box2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int units=0;
        
        for(auto it:boxTypes)
        {
            if(it[0] <= truckSize)
            {
                units += (it[0]*it[1]);
                truckSize -= it[0];
            }
            else
            {
                units += (truckSize*it[1]);
                break;
            }
            cout<<units<<endl;
        }
        return units;
        
    }
};