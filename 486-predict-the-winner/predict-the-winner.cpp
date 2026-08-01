class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int> &nums,int i,int j){

        if(i>j) return 0;
        

        if(dp[i][j]!=-1) return dp[i][j];
        int x=nums[i]-helper(nums,i+1,j);//front 
        int y=nums[j]-helper(nums,i,j-1);//back

        return dp[i][j]=max(x,y);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n,-1));
        return helper(nums,0,n-1)>=0;
    }
};