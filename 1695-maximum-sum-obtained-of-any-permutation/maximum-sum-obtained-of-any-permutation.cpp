class Solution {
public:
    using ll=long long;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int> diff(n,0);

        for(int i=0;i<requests.size();i++){
            diff[requests[i][0]]+=1;
            if(requests[i][1]+1 <n) diff[requests[i][1]+1]-=1;
        }

        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        sort(diff.begin(),diff.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());
        ll sum=0;
        ll mod=1e9+7;
        for(int i=0;i<n;i++){
            sum=((sum + diff[i] * 1ll*nums[i]) %mod);
        }
        return (int)sum;
    }
};