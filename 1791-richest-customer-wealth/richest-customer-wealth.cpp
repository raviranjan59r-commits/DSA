class Solution {
public:
    int maximumWealth(vector<vector<int>>& nums) {
        int max_sum=0;
        for(int i=0;i<nums.size();i++){
            int sum=accumulate(nums[i].begin(),nums[i].end(),0);

            max_sum=max(sum,max_sum);
        }
        return max_sum;
    }
};