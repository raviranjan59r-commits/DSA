class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(vector<int>&nums,long long i,bool even){
        if(i>=nums.size()) return 0;
        //not take
        if(dp[i][even]!=-1) return dp[i][even];

        long long not_take=solve(nums,i+1,even);
        long long take;
        if(even){
            take=solve(nums,i+1,!even) + nums[i];
        }
        else{
            take=solve(nums,i+1,!even) - nums[i];
        }

        return dp[i][even]=max(take,not_take);

    }
    long long maxAlternatingSum(vector<int>& nums) {
        long long n=nums.size();
        dp.resize(n+1,vector<long long>(2,0));

        for(int i=n-1;i>=0;i--){
            // even=true

            dp[i][1]=max(dp[i+1][1],nums[i]+dp[i+1][0]);


            // even=false

            dp[i][0]=max(dp[i+1][0],dp[i+1][1]-nums[i]);

            
        }
        return dp[0][1];
    }
};