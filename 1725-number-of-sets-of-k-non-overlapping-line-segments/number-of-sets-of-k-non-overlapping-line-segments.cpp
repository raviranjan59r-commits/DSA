class Solution {
public:
    int M=1e9+7;
    vector<vector<int>> dp;
    vector<vector<int>> sum;

    int f(int i,int k,int n){
        if(k==0) return 1;
        if(i>=n) return 0;

        if(dp[i][k]!=-1) return dp[i][k];

        //not take
        int skip=f(i+1,k,n);

        //take
        int take=sum[i+1][k-1];

        return dp[i][k]=(skip+take)%M;
    }

    int numberOfSets(int n,int k){
        dp.assign(n+1,vector<int>(k+1,-1));
        sum.assign(n+1,vector<int>(k+1,0));

        //k=0 => f(i,0)=1
        for(int i=0;i<n;i++)
            sum[i][0]=(n-i)%M;

        //precompute f values
        for(int K=1;K<=k;K++){
            for(int i=n-1;i>=0;i--){
                int skip=(i+1<n)?dp[i+1][K]:0;
                int take=(i+1<n)?sum[i+1][K-1]:0;

                dp[i][K]=(skip+take)%M;

                sum[i][K]=(dp[i][K]+sum[i+1][K])%M;
            }
        }

        return dp[0][k];
    }
};