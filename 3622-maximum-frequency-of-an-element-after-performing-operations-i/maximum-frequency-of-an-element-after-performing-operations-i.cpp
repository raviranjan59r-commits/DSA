class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        //method 2
        map<int,int> events;

        unordered_map<int,int> freq;
        for(int ele:nums){
            freq[ele]++;// calculate the freq
            events[ele]=0;// add this current ele to the event
        }


        for(int ele:nums){
            int l=ele-k;
            int r=ele+k;
            events[l]++;
            events[r+1]--;
        }
        //prefix sum of freq
        int freqency=0;
        for(auto &it:events){
            it.second+=freqency;
            freqency=it.second;
        }
        //now all the elements are present in sorted order and with their freq in it
        // important observation -> events will alaways contain the ans element as key in it
        int max_freq=0;
        for(auto & [ele,f]:events){
            int current_max_freq=min(numOperations,f-freq[ele]) + freq[ele];
            max_freq=max(max_freq,current_max_freq);
        }
        return max_freq;
    }
};