class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        int mn=nums[0];

        unordered_set<int> st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            st.insert(nums[i]);
            if(nums[i]>mx) mx=nums[i];
            else if(nums[i]<mn) mn=nums[i];
        }

        vector<int> ans;

        for(int i=mn;i<=mx;i++)
        {
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};