class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>>& triangle,int i,int j){//return minimum sum from top to bottom
        int r=triangle.size();
        // int c=r;

        if(i>=r) return 0;

        if(dp[i][j]!=1e9) return dp[i][j];

        int left_ans=triangle[i][j] + f(triangle,i+1,j);
        int right_ans=triangle[i][j] + f(triangle,i+1,j+1);

        return dp[i][j]=min(left_ans,right_ans);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(201,vector<int>(201,1e9));
        return f(triangle,0,0);
    }
};