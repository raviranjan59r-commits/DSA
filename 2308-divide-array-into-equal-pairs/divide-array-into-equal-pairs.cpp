class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> s;

        for(int ele:nums){
            if(s.count(ele)){
                s.erase(ele);
            }
            else s.insert(ele);
        }

        return s.empty();
    }
};