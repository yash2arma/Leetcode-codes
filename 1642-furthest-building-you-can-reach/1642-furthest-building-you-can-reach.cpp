class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int> maxBricks; //stores bricks used in each step in decreasing order
        
        int i=0, height_diff=0;
        
        //go until all bricks and ladders are used or reach at last building
        for(i=0; i<heights.size()-1; i++)
        {
            height_diff = heights[i+1]-heights[i];
            
            //if current building's height >= next building's height, we don't need a ladder  or bricks
            if(height_diff<=0) 
                continue;
            
            bricks -= height_diff; //subtract bricks used from total bricksj
            maxBricks.push(height_diff); //add bricks used in priority_queue
            
            if(bricks<0) //if we don't have enough bricks we use ladder
            {
                bricks += maxBricks.top(); //add max bricks used in previous buildings to total bricks
                maxBricks.pop();
                ladders--; //and used ladder their
            }
            
            if(ladders<0) //if all ladders are used we break so currect building is ans
                break;
        }
        return i;
    }
};