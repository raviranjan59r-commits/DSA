class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {

        int n=stones.size();

        vector<int> prefix(n,0);
        prefix[0]=stones[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }

        vector<int> ans(n,0);
        int max_ans=prefix[n-1];
        for(int i=n-2;i>=1;i--){
            max_ans=max(max_ans,prefix[i]-max_ans);
        }
        return max_ans;
    }
};