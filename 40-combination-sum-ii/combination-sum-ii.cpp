class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& arr, int target,vector<int>&temp,int idx){
        
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=arr.size()) return ;

        unordered_set<int> s;

        for(int i=idx;i<arr.size();i++){
            if(target-arr[i]>=0 && !s.count(arr[i])) {
                s.insert(arr[i]);
                temp.push_back(arr[i]);
                f(arr,target-arr[i],temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> temp;
        f(arr,target,temp,0);

        return ans;
    }
};