class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int second=INT_MAX;

        for(int ele:nums){
            if(ele<=first){
                first=ele;
            }
            else if(ele<=second){
                second=ele;
            }
            else {
                return true;
            }
        }
        return false;
    }
};