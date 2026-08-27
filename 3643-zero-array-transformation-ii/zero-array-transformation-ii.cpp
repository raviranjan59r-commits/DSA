class Solution {
public:
    bool  f(vector<int> &nums, vector<vector<int>>& queries,int mid){
        vector<int> diff(nums.size()+1,0);
        for(int i=0;i<=mid;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int v=queries[i][2];

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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                flag=true;
                break;
            }
        }
        if(!flag) return 0;

        int l=0;
        int r=queries.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(f(nums,queries,mid)){
                ans=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};