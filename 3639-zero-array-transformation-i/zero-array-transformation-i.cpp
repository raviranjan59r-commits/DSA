class Solution {
public:
    bool  f(vector<int> &nums, vector<vector<int>>& queries,int mid){
        vector<int> diff(nums.size()+1,0);
        for(int i=0;i<=mid;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int v=1;

            diff[l]-=v;
            diff[r+1]+=v;
        }
        //check for zero
        for(int i=1;i<diff.size();i++) diff[i]+=diff[i-1];
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]+ diff[i] > 0) return false;
        }
        return true;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        return f(nums,queries,queries.size()-1);
    }
};