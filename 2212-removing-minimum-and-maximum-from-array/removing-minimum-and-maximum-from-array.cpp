class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minidx=0;
        int maxidx=0;
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[minidx]>nums[i]){
                minidx=i;
            }
            if(nums[maxidx]<nums[i]){
                maxidx=i;
            }
        }
        int ans=0;
        int l=min(minidx,maxidx);//left most idx
        int r=max(minidx,maxidx);//right most idx

        // case 1 delete both from left
        int delete_left=r+1;
        //case 2 delete both from right
        int delete_right=n-l;

        // case 3 delete from both side
        int delete_both=(l+1) + (n-r); 

        return min({delete_left,delete_right,delete_both});

        return 0;
    }
};