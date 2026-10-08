class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lazy;

        for(int ele:nums){
            auto it=lower_bound(lazy.begin(),lazy.end(),ele);

            if(it==lazy.end()){
                lazy.push_back(ele);
            }
            else{
                *it=ele;
            }
        }
        return lazy.size();
    }
};