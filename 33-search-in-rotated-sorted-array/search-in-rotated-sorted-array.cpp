class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int idx=-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[l]){
                if(target>=nums[l] && target<nums[mid]){
                    h=mid-1;
                }
                else l=mid+1;
            }
            else{//nums[mid]<nums[low]
                if(target>nums[mid] && target<=nums[h] ){
                        l=mid+1;
                }
                else h=mid-1;
            }

        }
        return idx;
    }
};