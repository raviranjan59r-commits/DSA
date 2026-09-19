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
        memset(dp,0,sizeof(dp));
        // return LIS(nums,0,-1);
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            for(int prevIdx=i-1;prevIdx>=-1;prevIdx--){
                int skip=dp[i+1][prevIdx+1];

                int take=-1e9;

                if(prevIdx==-1 || nums[i]>nums[prevIdx]){
                    take=1+dp[i+1][i+1];
                }

                dp[i][prevIdx+1]=max(take,skip);
            }
        }
        return dp[0][0];
    }
};