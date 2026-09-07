class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp; // store no of loses

        for(auto &v:matches){
            mp[v[1]]++;
        }

        vector<int> not_lost;
        vector<int> one_lost;

        for(auto &v:matches){
            if(!mp.count(v[0])) not_lost.push_back(v[0]);
            if(!mp.count(v[1])) not_lost.push_back(v[0]);
        }

        for(auto &[player,loss]:mp){
            if(loss==1) one_lost.push_back(player);
        }
        sort(not_lost.begin(),not_lost.end());
        not_lost.erase(unique(not_lost.begin(),not_lost.end()),not_lost.end());//remove duplicate elemrnts

        return {not_lost,one_lost};
    }
};