class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<pair<int,int>> new_color;
    void helper(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited){
        

        visited[row][col]=1;

        for(auto v:dir){
            int new_row=row+v[0];
            int new_col=col+v[1];
            if(new_row<0 || new_col<0 || new_row>=grid.size() || new_col>=grid[0].size() || grid[row][col]!=grid[new_row][new_col]){
                new_color.push_back({row,col});
                continue;
            }
            if(!visited[new_row][new_col]) helper(grid,new_row,new_col,visited);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col]==color) return grid;

        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
       
        helper(grid,row,col,visited);

        for(auto &[a,b]:new_color){
            grid[a][b]=color;
        }
        return grid;
    }
};