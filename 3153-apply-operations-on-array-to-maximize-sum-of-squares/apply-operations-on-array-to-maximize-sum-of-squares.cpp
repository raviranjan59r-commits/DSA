class Solution {
public:
    int M=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32,0);

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                count[j]+=(nums[i]>>j) & 1;
            }
        }
        long long sum=0;
        while(k--){
            long long num=0;
            for(int i=0;i<32;i++){
                if(count[i]){
                    num+=pow(2,i);
                    count[i]--;
                }
            }
            sum=(sum+num*num)%M;
        }
        return sum;
    }
};