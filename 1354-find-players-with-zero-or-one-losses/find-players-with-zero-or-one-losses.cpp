class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> win;
        map<int,int> loss;

        for(auto &v:matches){
            win[v[0]]++;
            loss[v[1]]++;
        }

        vector<int> not_lost;
        vector<int> one_lost;

        for(auto &[player,lose]:loss){
            if(lose==1) one_lost.push_back(player);
        }
        for(auto &[player,w]:win){
            if(!loss.count(player)) not_lost.push_back(player);
        }
       

        return {not_lost,one_lost};
    }
};