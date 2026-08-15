class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
            if(nums[i]!=0) flag=true;
        }

        if(!flag) return 0;

        if(ans!=0) return nums.size();
        return nums.size()-1;

    }
};