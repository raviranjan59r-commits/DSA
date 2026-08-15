class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        unordered_map<int,int> unique_freq;

        for(auto ele:freq){
            unique_freq[ele.second]++;
        }

        for(int i=0;i<nums.size();i++){
            int num_freq=freq[nums[i]];
            int freq_num_freq=unique_freq[num_freq];

            if(freq_num_freq==1) return nums[i];
        }
        return -1;
    }
};