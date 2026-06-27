class Solution {
public:
    vector<vector<int>> ans;
    void f(int k,int target,vector<int>&temp,int idx){
        if(target==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=10 || k<0 ) return ;

        for(int i=idx;i<=9;i++){
            if(target-i>=0) {
                temp.push_back(i);
                f(k-1,target-i,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;

        f(k,n,temp,1);

        return ans;
    }
};