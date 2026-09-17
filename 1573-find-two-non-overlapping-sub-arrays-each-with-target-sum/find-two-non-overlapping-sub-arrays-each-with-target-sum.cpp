class Solution {
public:
    vector<int> prefix(int target,vector<int>&nums){
        vector<int> pre(nums.size(),0);
        int sum=0;
        int idx=1e9;
        int best=1e9;
        int i=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>target){
                sum-=nums[i];
                i++;
            }
            if(sum==target){
               best=min(best,j-i+1);
            }
            pre[j]= best==1e9?0:best;
        }
        return pre;
    }
    vector<int> suffix(int target,vector<int>&nums){
        vector<int> suff(nums.size(),0);
        int sum=0;
        int idx=1e9;
        int best=1e9;
        int i=nums.size()-1;
        for(int j=nums.size()-1;j>=0;j--){
            sum+=nums[j];
            while(sum>target){
                sum-=nums[i];
                i--;
            }
            if(sum==target){
               best=min(best,i-j+1);
            }
            suff[j]= best==1e9?0:best;
        }
        return suff;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        //optimal

        int n=arr.size();
        vector<int>pre=prefix(target,arr);
        vector<int> suff=suffix(target,arr);
        int res=1e9;

        for(int i=1;i<n;i++){
            if(pre[i-1]==0 || suff[i]==0) continue;

            res=min(res,pre[i-1]+suff[i]);
        }
        return res==1e9?-1:res;
    }
};