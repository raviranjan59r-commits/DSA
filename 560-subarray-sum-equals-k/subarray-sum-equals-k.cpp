class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        int sum=0;
        int count=0;
        freq[0]=1;
        for(auto num:nums){
            sum+=num;
            int need=sum-k;

            if(freq.count(need)){
                count+=freq[need];
            }

            freq[sum]++;
        }
        return count;
    }
};