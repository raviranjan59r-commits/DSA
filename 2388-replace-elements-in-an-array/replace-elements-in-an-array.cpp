class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;// it will stroe ele:index

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }

        for(int i=0;i<operations.size();i++){
            int idx=mp[operations[i][0]];
            mp.erase(operations[i][0]);
            mp[operations[i][1]]=idx;
            nums[idx]=operations[i][1];
        }
        
        return nums;
    }
};