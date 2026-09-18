class Solution {
public:
    int dp[2501][2502];
    int LIS(vector<int>& nums,int i,int prevIdx){
        if(i>=nums.size()) return 0;
        // two cases
        // skip
        if(dp[i][prevIdx+1]!=-1) return dp[i][prevIdx+1];
        int skip=LIS(nums,i+1,prevIdx);

        //take
        int take=-1e9;
        if(prevIdx==-1 || nums[i]>nums[prevIdx]){
            take=1+LIS(nums,i+1,i);
        }

        return dp[i][prevIdx+1] = max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return LIS(nums,0,-1);
    }
};