class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller=0;
        int count=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) count++;
            else if(nums[i]<target) smaller++;
        }

        vector<int> ans;

        while(count--){
            ans.push_back(smaller);
            smaller++;
        }
        return ans;
    }
};