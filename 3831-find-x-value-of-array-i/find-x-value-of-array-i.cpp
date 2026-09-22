class Solution {
public:
    using ll=long long;
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<vector<ll>> dp(nums.size(),vector<ll>(k,0));

        int r=nums[0]%k;
        dp[0][r]++;

        for(int i=1;i<nums.size();i++){
            ll newRem=(nums[i])%k;

            dp[i][newRem]++;
            for(int j=0;j<k;j++){
                ll rem=(1LL * j*nums[i])%k;
                dp[i][rem]+=dp[i-1][j];
            }
        }
        //return prefix sum
        vector<ll> ans(k,0);

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<k;j++){
                ans[j]+=dp[i][j];
            }
        }
        return ans;
    }
};