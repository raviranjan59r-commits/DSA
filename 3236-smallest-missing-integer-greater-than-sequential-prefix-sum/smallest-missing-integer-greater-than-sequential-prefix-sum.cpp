class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]+1;
        int i=1;
        int sum=nums[0];
        while(i<n){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
                i++;
            }
            else{
                break;
            }
        }

        //finding the smallest missing number

        unordered_set<int> st;

        for(int ele:nums) st.insert(ele);

        while(true){
            if(st.find(sum)!=st.end()){
                sum++;
            }
            else{
                break;
            }
        }
        return sum;
    }
};