class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> preSum(n+1,0);
        vector<int> suffSum(n+1,0);

        //fill prefix sum
        for(int i=1;i<=n;i++){
            preSum[i]=preSum[i-1] + nums[i-1];
        }
        // fill suffix sum
        for(int i=n-1;i>=0;i--){
            suffSum[i]=suffSum[i+1] + nums[i];
        }
        // iterate through suffSum
        int minOp=INT_MAX;
        for(int i=n;i>=0;i--){
            if(suffSum[i]>x) break;
            int y=x-suffSum[i];

            auto it=lower_bound(preSum.begin(),preSum.begin()+i+1,y);

            if(it!=preSum.begin()+i+1 && *it==y){
                int len=n-i + (it-preSum.begin());
                minOp=min(minOp,len);
            }
        }

        return minOp==INT_MAX?-1:minOp;
        
    }
};