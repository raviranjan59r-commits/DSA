class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int last=arr[0][1];
        for(int i=1;i<arr.size();i++){
            int currf=arr[i][0];
            if(currf<=last){
                last=max(arr[i][1],last);
                ans[ans.size()-1][1]=last;
            }
            else{
                ans.push_back(arr[i]);
                last=arr[i][1];
            }
        }
        return ans;
    }
};