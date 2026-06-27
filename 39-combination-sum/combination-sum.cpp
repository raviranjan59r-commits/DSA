class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& arr, int target,vector<int>&temp,int idx){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=arr.size()) return ;

        for(int i=idx;i<arr.size();i++){
            if(target-arr[i]>=0) {
                temp.push_back(arr[i]);
                f(arr,target-arr[i],temp,i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;
        f(candidates,target,temp,0);

        return ans;
    }
};