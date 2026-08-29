class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> diff(mx+2,0);
        unordered_map<int,int> mp;
        for(auto & ele:nums){
            int l=max(0,ele-k);
            int r=min(mx,ele+k);
            mp[ele]++;

            diff[l]++;
            diff[r+1]--;
        }
        //prefix sum

        for(int i=1;i<diff.size();i++){
            diff[i]+=diff[i-1];
        }
       int max_freq=0;
        for(int i=0;i<=mx;i++){
            int current_ele_max_freq=min(diff[i]-mp[i],numOperations)   + mp[i];
            max_freq=max(max_freq,current_ele_max_freq);
        }
        return max_freq;

    }
};