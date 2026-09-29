class Solution {
public:
    struct node{
        int r;
        int c;
        int x;
    };
    vector<vector<int>> dir={{1,0},{0,1}};
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][0]==')') return false;
        if(grid[m-1][n-1]=='(') return false;

        vector<vector<vector<bool>>> visited(
            m,vector<vector<bool>>(n,vector<bool>(m+n+1,false))
        );
        queue<node> q;

        q.push({0,0,1});
        visited[0][0][1]=true;

        while(!q.empty()){
            auto temp=q.front();
            int r=temp.r;
            int c=temp.c;
            int x=temp.x;
            q.pop();

            if(r==m-1 && c==n-1 && x==0){
                return true;
            }

            for(int i=0;i<2;i++){
                int newr=r+dir[i][0];
                int newc=c+dir[i][1];
                if(newr>=m || newc>=n ) continue;
                int newx;

                if(grid[newr][newc]=='('){
                    newx=x+1;
                }
                else{
                    if(x==0) continue;
                    newx=x-1;
                }
                if(visited[newr][newc][newx]) continue;

                visited[newr][newc][newx]=true;
                q.push({newr,newc,newx});   
            }

        }
        return false;
    }
};