class Solution {
public:
    vector<int> dp;
    int f(vector<int>& nums,int idx){// it will return minimum step to jump from idx to n-1
        int n=nums.size();
        if(idx>=n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=1e9;

        for(int i=1;i<=nums[idx];i++){
            int curr_ans=1+f(nums,idx+i);
            ans=min(curr_ans,ans);
        }

        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return f(nums,0);
    }
};