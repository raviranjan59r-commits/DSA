class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);

        dp[1]=true;

        for(int i=2;i<=n;i++){
            int square_num=sqrt(i);

            for(int j=1;j<=square_num;j++){
                if(dp[i-j*j]==false) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};