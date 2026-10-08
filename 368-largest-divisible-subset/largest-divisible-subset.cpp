class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();

        vector<int> dp(n,1);
        vector<int> prevIdx(n,-1);

        int idx=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prevIdx[i]=j;
                    }

                    if(dp[idx]<dp[i]){
                        idx=i;
                    }
                }
            }
        }

        vector<int> ans;
        while(true){
            if(prevIdx[idx]==-1){
                ans.push_back(nums[idx]);
                break;
            }
            ans.push_back(nums[idx]);
            idx=prevIdx[idx];
        }
        return ans;
    }
};