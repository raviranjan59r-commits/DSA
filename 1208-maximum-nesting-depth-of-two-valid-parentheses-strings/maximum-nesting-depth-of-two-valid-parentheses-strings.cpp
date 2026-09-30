class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int balanced=0;
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            char ch=seq[i];
            if(ch=='('){
                balanced++;
                ans[i]=balanced%2;
            }
            else {
                ans[i]=balanced%2;
                balanced--;
            }
            
        }
        return ans;
    }
};