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
        // iterate through preSum
        int minOp=INT_MAX;
        for(int i=0;i<=n;i++){
            if(preSum[i]>x) break;
            int y=x-preSum[i];

            auto it=lower_bound(suffSum.rbegin(),suffSum.rend()-i-1,y);

            if(it!=suffSum.rend() && *it==y){
                int len=i+(it-suffSum.rbegin());
                minOp=min(minOp,len);
            }
        }

        return minOp==INT_MAX?-1:minOp;
        
    }
};