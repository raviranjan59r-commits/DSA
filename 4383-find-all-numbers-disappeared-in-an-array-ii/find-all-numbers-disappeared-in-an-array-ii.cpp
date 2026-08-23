class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int current_lo=-1;
        int current_hi=-1;
        for(int i=lower;i<=upper;i++){
            if(binary_search(nums.begin(),nums.end(),i)){
                if(current_lo==-1)continue;
                else{
                    ans.push_back({current_lo,current_hi});
                    current_lo=-1;
                }
            }
            else{
                if(current_lo==-1){
                    current_lo=current_hi=i;
                }
                else{
                    current_hi=i;
                }
            }
        }
        if(current_lo!=-1) ans.push_back({current_lo,current_hi});
        return ans;
    }
};