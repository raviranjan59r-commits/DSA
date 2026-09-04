class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        // calculate prefix maximum
        vector<int> prefix_maximum(n,-1);
        prefix_maximum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix_maximum[i]=max(prefix_maximum[i-1],nums[i]);
        }

        // suffix minimum
        vector<int> suffix_minimum(n,-1);
        suffix_minimum[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffix_minimum[i]=min(suffix_minimum[i+1],nums[i]);
        }

        // calculate ans
        int idx=-1;
        for(int i=0;i<n;i++){
            if(prefix_maximum[i]-suffix_minimum[i] <= k ){
                return i;
            }
        }
        return idx;
    }
};