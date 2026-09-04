class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // minor optimisation

        int n=nums.size();
        // suffix minimum
        vector<int> suffix_minimum(n,-1);
        suffix_minimum[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffix_minimum[i]=min(suffix_minimum[i+1],nums[i]);
        }

        // calculate prefix maximum and calculate ans
        vector<int> prefix_maximum(n,-1);
        prefix_maximum[0]=nums[0];
        if(prefix_maximum[0]-suffix_minimum[0] <= k ){
            return 0;
        }
        int idx=-1;

        for(int i=1;i<n;i++){
            prefix_maximum[i]=max(prefix_maximum[i-1],nums[i]);
            if(prefix_maximum[i]-suffix_minimum[i] <= k ){
                return i;
            }
        }

        return idx;
    }
};