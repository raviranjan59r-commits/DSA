class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+3,0);

        for(int i=n-1;i>=0;i--){
            int a = nums[i] - dp[i+1];

            int b = INT_MIN;

            if ((i + 1) < nums.size())
                b = nums[i] + nums[i + 1] - dp[i+2];

            int c = INT_MIN;

            if ((i + 2) < nums.size())
                c = nums[i] + nums[i + 1] + nums[i + 2] - dp[i+3];

            dp[i]=max({a,b,c});
            }
        if (dp[0]>0) return "Alice";
        if(dp[0]==0) return "Tie";
        return "Bob";
    }
};