class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(auto ele:nums) freq[ele]++;
        int max_freq=0;
        for(auto &it:freq){
            max_freq=max(it.second,max_freq);
        }
        int ans=0;

        for(auto &it:freq){
            if(it.second==max_freq){
                ans++;
            }
        }
        return ans*max_freq;
    }
};