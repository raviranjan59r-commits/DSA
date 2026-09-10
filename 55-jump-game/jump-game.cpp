class Solution {
public:
    vector<int> dp;
    bool f(vector<int>& nums,int idx){// it will return if we can jump from idx to n-1
        int n=nums.size();
        if(idx==n-1) return 1;
        else if (idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];

        for(int i=1;i<=nums[idx];i++){
            bool curr_ans=f(nums,idx+i);
            if(curr_ans) return dp[idx]=true;
        }

        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return f(nums,0);
    }
};