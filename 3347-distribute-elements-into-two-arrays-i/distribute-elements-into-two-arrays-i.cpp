class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;

        if(nums.size()==1) return nums;

        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        int i=2;

        while(i<nums.size()){
            if(v1.back()>v2.back()){
                v1.push_back(nums[i]);
                i++;
            }
            else{
                v2.push_back(nums[i]);
                i++;
            }
        }
        v1.insert(v1.end(),v2.begin(),v2.end());
        return v1;
    }
};