class Solution {
public:
vector<vector<int>> dp;
int helper(vector<int>& piles,int i,int j){
    if(i==j) return piles[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(piles[i]-helper(piles,i+1,j)  ,  piles[j]-helper(piles,i,j-1));
}
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        return helper(piles,0,n-1)>0;
    }
};