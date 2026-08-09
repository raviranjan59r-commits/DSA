class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int> & piles,int i,int m){
        if(i>=piles.size()) return 0;
        if(dp[i][m]!=INT_MIN) return dp[i][m];
        int sum=0;
        int ans=INT_MIN;
        for(int t=i;t<(i+2*m);t++){
            if(t>=piles.size()) break;
            sum+=piles[t];
            ans=max(ans,sum-helper(piles,t+1,max(m,t-i+1)));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        dp.resize(100,vector<int>(100,INT_MIN));
        int total = accumulate(piles.begin(), piles.end(), 0);//alice + bob
        int diff = helper(piles, 0, 1);//alice - bob
        return (total + diff) / 2;// (alice + bob + alice - bob)/2  == alice
    }
};