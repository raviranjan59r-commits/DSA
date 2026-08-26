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

        ll left=-1;
        ll right=-1;
        long long current_col=0;
        // now we do have the sorted 
        for(auto &[interval,delta]:mp){
            if(left==-1){
                left=interval;
            }
            else{
                if(current_col==0){
                    current_col+=delta;
                    left=interval;
                    continue;
                }
                ans.push_back({left,interval,current_col});
                left=interval;
            }
            current_col+=delta;
        }
        return ans;
    }
};