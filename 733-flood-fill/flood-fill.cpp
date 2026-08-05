class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void helper(vector<vector<int>>&image,int sr,int sc,int oldcolor,int newcolor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=oldcolor){
            return;
        }
        image[sr][sc]=newcolor;

        for(auto v:dir){
            int r=v[0];
            int c=v[1];

            helper(image,sr+r,sc+c,oldcolor,newcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        helper(image,sr,sc,image[sr][sc],color);

        return image;
    }
};