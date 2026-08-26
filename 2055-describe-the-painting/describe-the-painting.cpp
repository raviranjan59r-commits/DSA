class Solution {
public:
    using ll = long long;
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<ll,ll> mp;

        for(auto &s:segments){
            mp[s[0]]+=s[2];
            mp[s[1]]-=s[2];
        }

        vector<vector<long long>> ans;

        ll prev=-1;
        long long color=0;
        // now we do have the sorted 
        for(auto &[interval,delta]:mp){
            if(prev!=-1 && color!=0){
                ans.push_back({prev,interval,color});
            }
            prev=interval;
            color+=delta;
        }
        return ans;
    }
};