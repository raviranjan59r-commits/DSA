class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> freq;
        int ans=-1;

        int i=0,j=0;

        while(i<n && j<n){
            while(j<n && freq[nums[j]]<k){
                freq[nums[j]]++;
                ans=max(ans,j-i+1);
                j++;
            }
            freq[nums[i]]--;
            i++;
        }

        return ans;
    }
};