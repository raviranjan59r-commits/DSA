class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n=nums.size();
        if(n==k) return *max_element(nums.begin(),nums.end());
        unordered_map<int,int> freq;

        for(int ele:nums) freq[ele]++;

        if(k==1){
            int ans=-1;
            for(auto & [a,f]:freq){
                if(f==1 && a>ans){
                    ans=a;
                }
            }
            return ans;
        }

        if(freq[nums[0]]==1 && freq[nums[n-1]]==1){
            return max(nums[0],nums[n-1]);
        }

        if(freq[nums[0]]==1) return nums[0];
        if(freq[nums[n-1]]==1) return nums[n-1];

        return -1;
    }
};