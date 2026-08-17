class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix_sum;
    int helper(vector<int>& nums,int lo,int hi){//this return maximum value of alice in nums from idx lo to high 
        if(hi<=lo) return 0;
        // cout<<lo<<" "<<hi<<endl;
        if(dp[lo][hi]!=-1) return dp[lo][hi];
        int ans=INT_MIN;
        for(int i=lo;i<=hi;i++){
            int left_sum  = prefix_sum[i+1] - prefix_sum[lo];
            int right_sum = prefix_sum[hi+1] - prefix_sum[i+1];

            if(left_sum<right_sum){
                ans=max(ans,left_sum + helper(nums,lo,i));
            }
            else if(left_sum>right_sum){
                ans=max(ans,right_sum+helper(nums,i+1,hi));
            }
            else{
                ans=max({left_sum + helper(nums,lo,i),right_sum+helper(nums,i+1,hi),ans});
            }
            
        }
        return dp[lo][hi] = ans;

    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();

        dp.resize(n,vector<int>(n,-1));
        prefix_sum.resize(n+1,0);

        for(int i=0;i<n;i++){
            prefix_sum[i+1]=prefix_sum[i]+stoneValue[i];
        }

        return helper(stoneValue,0,n-1);
    }
};