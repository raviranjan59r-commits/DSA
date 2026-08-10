class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> res=nums;
        for(int i=nums.size()-1;i>=0;i--){
            res.push_back(nums[i]);
        }
        return res;
    }
};