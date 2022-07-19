class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int pixel)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]==color || image[sr][sc]!=pixel) return;
        
        image[sr][sc] = color;
        
        dfs(image, sr-1, sc, color, pixel);
        dfs(image, sr+1, sc, color, pixel);
        dfs(image, sr, sc-1, color, pixel);
        dfs(image, sr, sc+1, color, pixel);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int pixel = image[sr][sc];
        dfs(image, sr, sc, color, pixel);
        return image;
    }
};