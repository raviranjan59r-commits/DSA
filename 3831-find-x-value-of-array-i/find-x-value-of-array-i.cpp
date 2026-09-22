class Solution {
public:
    using ll=long long;
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<vector<ll>> dp(nums.size(),vector<ll>(k,0));

        int rem=nums[0]%k;
        dp[0][rem]++;

        for(int i=1;i<nums.size();i++){
            rem=(nums[i])%k;

            dp[i][rem]++;
            for(int j=0;j<k;j++){
                ll newRem=(1LL * j*nums[i])%k;
                dp[i][newRem]+=dp[i-1][j];
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