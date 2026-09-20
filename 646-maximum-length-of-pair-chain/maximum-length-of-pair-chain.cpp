class Solution {
public:
    int t[1001][1001];
    int solve(vector<vector<int>> &nums,int i,int lastIdx){
        if(i>=nums.size()) return 0;

        if(lastIdx!=-1 &&  t[i][lastIdx]!=-1) return t[i][lastIdx];

        int skip=solve(nums,i+1,lastIdx);

        int take=0;

        if(lastIdx==-1 || nums[lastIdx][1]<nums[i][0]){
            take=1+solve(nums,i+1,i);
        }
        if(lastIdx!=-1){
            t[i][lastIdx]=max(skip,take);
        }
        return max(skip,take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();

        sort(pairs.begin(),pairs.end());

        memset(t,-1,sizeof(t));

        return solve(pairs,0,-1);
    }
};