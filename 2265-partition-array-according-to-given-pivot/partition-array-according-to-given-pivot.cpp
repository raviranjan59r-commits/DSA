class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> res(n,pivot);
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) res[j++]=nums[i];
        }
        j=n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>pivot) res[j--]=nums[i];
        }
        return res;
    }
};